This project has been created as part of the 42 curriculum by aforcada.

# Description

Minitalk is a simple interprocess communication. Here the server prints its process id (pid) with `getpid`, checks for an incoming signal with `pause`, and handles the signal with `sigaction`. A client can send a signal to the server using the pid of the server and a signal number as input of `kill`. By using the signals `SIGUSR1` and `SIGUSR2`, abstracted to `0` and `1`, a message string can be sent bit by bit from the client to the server.

To ensure the signal received by the server has enough time to get processed, `usleep` was used to wait between signals.

To mask other signals during a signal processing `sigaddset` is used.

To treat one client at a time and prevent an overlap the `signal_handler` in the server is expanded to use `siginfo_t` by setting the `sigaction.sa_flags` field to `SA_SIGINFO`. Inside the `siginfo_t` structure the `si_pid` gives the signal sender pid, in other words the client id. Keeping track of the message is then a simple id check combined with waiting time.

# Instructions

- Run `make` to get the `server` and `client` executables.
- Run `./server` to get the server running.
- Copy the pid given by the server.
- Run `./client <pid> <sting>` to send the message string to the server.


# Resources

- version 5.10 of the man pages on the functions/structures used (see [Description](#description))
- for signal understanding, [codevault sigusr1/2](https://www.youtube.com/watch?v=PErrlOx3LYE&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=20)
- for signal understanding, [Shawn's explanation](https://stackoverflow.com/questions/62176213/can-we-send-parameters-to-a-signal-handler-using-sigaction)
- for signal understanding (briefly explored): **Kerrisk, Michael**. _The Linux Programming Interface: A Linux and UNIX System Programming Handbook_. No Starch Press, 2010.
- AI [deepseek](https://chat.deepseek.com) was used for troubleshooting, e.g. the server could'nt handle several clients and the error came from not sending the end of string character `\0`.
