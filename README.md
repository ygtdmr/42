*This project has been created as part of the 42 curriculum by ygtdmr.*

# minitalk

## Description

minitalk implements inter-process message transfer with UNIX signals. The client encodes each character bit by bit with SIGUSR1 and SIGUSR2; the server reconstructs bytes in a signal handler and prints the received message. The bonus sources provide the corresponding bonus client/server variants.

The Makefile builds client and server from the mandatory sources. The project demonstrates process identifiers, asynchronous signal delivery, bit manipulation, and the limitations of a simple signal-based protocol.

## Instructions

A C compiler and GNU Make are required:

~~~sh
make
~~~

The default target builds server and client. Start the server first, copy its printed PID, then send a message:

~~~sh
./server
./client SERVER_PID "hello from minitalk"
~~~

The Makefile also provides bonus, clean, fclean, and re. make bonus builds the bonus source variants into the server and client executable names; run them with the same client/server command pattern. The implementation uses a short usleep delay between signals, so messages should be sent through the provided client.

## Resources

- [POSIX signal](https://pubs.opengroup.org/onlinepubs/9699919799/functions/signal.html)
- [POSIX kill](https://pubs.opengroup.org/onlinepubs/9699919799/functions/kill.html)
- [POSIX pause](https://pubs.opengroup.org/onlinepubs/9699919799/functions/pause.html)
- The 42 minitalk subject is the reference for the client/server protocol and bonus requirements.

### AI Usage

AI was used during this repository task to inspect the signal protocol, verify the Makefile target names and runtime argument order, and draft this README. The original C implementation remains unchanged.

