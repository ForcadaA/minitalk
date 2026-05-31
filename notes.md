# minitalk

## notes from codevault unix processes in C 
- [codevault sigusr1/2](https://www.youtube.com/watch?v=PErrlOx3LYE&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=20)
communicating with signals between two processes
- `getppid` get parent pid
- `SIGUSR1/2` terminates process by default
- reset everything to 0 with `struct sigaction sa = { 0 };`
- if `scanf` set `sa.sa_flags = SA_RESTART;`
- set handler as `sa.sa_handler = &handle_usr1;`
- then call `sigaction(SIGUSR1, &sa, NULL);`


## sending parameters with a signal handler
- [stackoverflow Shawn](https://stackoverflow.com/questions/62176213/can-we-send-parameters-to-a-signal-handler-using-sigaction)
- Shawn's answer gives, makes use of `siginfo_t` and `sigqueue`
- the field `si_ptr` and `si_int` can be populated with data
- there is a `void *context` in the handler not sure why...
- the usr can fill in the last argument of `sigqueue` with the msg with `(union sigval){ .sival_ptr = ... }`


## man pages

This section extracted lines from version 5.10 of [man pages](https://www.kernel.org/doc/man-pages/).

### sigaction

```C
int	sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

The  `sigaction()`  system  call  is  used to change the action taken by a process on receipt of a specific signal. `signum` specifies the signal and can be any valid signal except `SIGKILL` and `SIGSTOP`. If `act` is non-`NULL`, the new action for signal `signum` is installed from `act`.  If `oldact` is non-`NULL`, the  previous action is saved in `oldact`.


The `sigaction` structure is defined as something like:

```C
struct sigaction {
	void		(*sa_handler)(int);
	void		(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t	sa_mask;
	int			sa_flags;
	void		(*sa_restorer)(void);
};
```

On some architectures a `union` is involved: do not assign to both `sa_handler` and `sa_sigaction`.

The  `sa_restorer`  field is not intended for application use.  (POSIX does not specify a `sa_restorer` field.)  Some further details of the purpose of this field can be found in `sigreturn`(2).

`sa_handler` specifies the action to be associated with `signum` and is be one of the following:

* `SIG_DFL` for the default action.

* `SIG_IGN` to ignore this signal.

* A pointer to a signal handling function.  This function receives the signal number as its only argument.

If `SA_SIGINFO` is specified in `sa_flags`, then `sa_sigaction` (instead of `sa_handler`) specifies  the  signal-handling function for `signum`.

`sa_mask`  specifies  a  mask  of  signals which should be blocked (i.e., added to the signal mask of the thread in which the signal handler is invoked) during execution of the signal handler.  In addition, the signal which triggered the handler will be blocked, unless the `SA_NODEFER` flag is used.

`sa_flags`  specifies  a  set  of flags which modify the behavior of the signal.
It is formed by the bitwise OR of zero or more of the following:

* `SA_NOCLDSTOP` $\quad$
If `signum` is `SIGCHLD`, do not receive notification when child processes stop (i.e., when they  receive  one of SIGSTOP, SIGTSTP, SIGTTIN, or SIGTTOU) or resume (i.e., they receive SIGCONT) (see wait(2)).
This flag is meaningful only when establishing a handler for `SIGCHLD`.

* `SA_NOCLDWAIT` (since Linux 2.6) $\quad$
If `signum` is `SIGCHLD`, do not transform children into zombies when they terminate.   See  also  `waitpid`(2).
This flag is meaningful only when establishing a handler for `SIGCHLD`, or when setting that signal's disposition to `SIG_DFL`.
If the `SA_NOCLDWAIT` flag is set when establishing a handler for `SIGCHLD`,  POSIX.1  leaves  it  unspecified whether a `SIGCHLD` signal is generated when a child process terminates.
On Linux, a `SIGCHLD` signal is generated in this case; on some other implementations, it is not.

* `SA_NODEFER` $\quad$
Do not add the signal to the thread's signal mask while the handler is executing,  unless  the  signal  is specified  in  `act.sa_mask`.
Consequently, a further instance of the signal may be delivered to the thread while it is executing the handler.
This flag is meaningful only when establishing a signal handler.

* `SA_ONSTACK`
Call the signal handler on an alternate signal stack provided by `sigaltstack`(2).
If an alternate stack is not  available,  the  default stack will be used.
This flag is meaningful only when establishing a signal handler.

* `SA_RESETHAND`
Restore the signal action to the default upon entry to the signal handler.  
This flag is  meaningful  only when establishing a signal handler.

* `SA_RESTART`
Provide  behavior  compatible  with BSD signal semantics by making certain system calls restartable across signals.
This flag is meaningful only when establishing a signal handler.
See `signal`(7) for a discussion of system call restarting.

* `SA_RESTORER`
Not intended for application use.
This flag is used by C libraries to indicate that the sa_restorer field contains the address of a "signal trampoline".
See `sigreturn`(2) for more details.

* `SA_SIGINFO` (since Linux 2.2)
The signal handler takes three arguments, not one. 
In this case, `sa_sigaction` should be  set  instead  of `sa_handler`.
This flag is meaningful only when establishing a signal handler.

> RETURN $\quad$
`sigaction()` returns 0 on success; on error, -1 is returned, and `errno` is set to indicate the error.

> ERRORS $\qquad$
`EFAULT` $\quad$
`act` or `oldact` points to memory which is not a valid part of the process address space. $\qquad$
`EINVAL` $\quad$
An  invalid  signal was specified.
This will also be generated if an attempt is made to change the action
for `SIGKILL` or `SIGSTOP`, which cannot be caught or ignored.


### siginfo_t

The following `struct` was copied starting line 380 from `man 3 siginfo_t`.

```C
typedef struct {
	int      si_signo;  /* Signal number */
	int      si_code;   /* Signal code */
	pid_t    si_pid;    /* Sending process ID */
	uid_t    si_uid;    /* Real user ID of sending process */
	void    *si_addr;   /* Address of faulting instruction */
	int      si_status; /* Exit value or signal */
	union sigval si_value;  /* Signal value */
} siginfo_t;
```


### sigval

The following `union` was copied starting line 408 from `man 3 sigval`.

```C
union sigval {
	int     sigval_int; /* Integer value */
	void   *sigval_ptr; /* Pointer value */
};
```


### sigqueue

The following function description was copied from `man 3 sigqueue`

```C
int sigqueue(pid_t pid, int sig, const union sigval value);
```

- `sigqueue()`  sends  the  signal specified in `sig` to the process whose PID is given in `pid`.  The permissions required to send a signal are the same as for `kill`(2).  As with `kill`(2), the `null` signal (0) can be used to check if a process with a given PID exists.

- The  value  argument  is  used to specify an accompanying item of data (either an integer or a pointer value) to be sent with the signal, and has the type `sigval`

- If the receiving process has installed a handler for this signal using the `SA_SIGINFO` flag  to  `sigaction`(2),  then it can obtain this data via the `si_value` field of the `siginfo_t` structure passed as the second argument to the handler. Furthermore, the `si_code` field of  that  structure  will  be  set  to `SI_QUEUE`.

- On  success, `sigqueue()` returns 0, indicating that the signal was successfully queued to the receiving process.  Otherwise, -1 is returned and `errno` is set to indicate the error.


## thoughts

### peer suggestions
- the linux programming interface as in depth reference
- the message have to be sent as bits and reconstructed on the server, does not align with [Shawn's answer](#sending-parameters-with-a-signal-handler).
- 

### signals
- `sigqueue` is not allowed for this project so understanding what it does to reproduce it with `sigaction` is most likely the way

### instructions
- running `server` in one terminal and then the `client` with `args` in another should be the way to execute the program
- the `server` shouldn't get input so a main without `args` can be setup to print its `pid`. 
- after the `pid` is print it should be waiting for the `client` to send it the `msg`
- so it should `wait` for the signal `SIGUSR1/2`
- the `client` should have a main with `args` and 2 inputs
- the first should be the `pid` of the `server` and the second should be the `msg`

