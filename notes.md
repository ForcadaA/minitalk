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
- the usr can fill in `sigqueue` with the msg with `(union sigval){ .sival_ptr = ... }`

## man pages
- the following `struct` copied from line 380 in man version 5.10, see [man pages](https://www.kernel.org/doc/man-pages/) describes the `siginfo_t`

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

- the following `union` copied from line 408 in man version 5.10, see [man pages](https://www.kernel.org/doc/man-pages/) describes  `sigval`

```C
union sigval {
	int     sigval_int; /* Integer value */
	void   *sigval_ptr; /* Pointer value */
};
```

- the following describes `sigqueue`

## thoughts

### signals
- `sigqueue` is not allowed for this project so understanding what it does to reproduce it with `sigaction` is most likely the way

### instructions
- running `server` in one terminal and then the `client` with `args` in another should be the way to execute the program
- the `server` shouldn't get input so a main without `args` can be setup to print its `pid`. 
- after the `pid` is print it should be waiting for the `client` to send it the `msg`
- so it should `wait` for the signal `SIGUSR1/2`
- the `client` should have a main with `args` and 2 inputs
- the first should be the `pid` of the `server` and the second should be the `msg`

