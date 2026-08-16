*This project has been created as part of the 42 curriculum by ygtdmr.*

# get_next_line

## Description

get_next_line reads one line at a time from a file descriptor. The mandatory implementation keeps a static read buffer, merges chunks until a newline or end-of-file is reached, and returns an allocated string without the trailing newline handling being hidden from the caller. The bonus implementation keeps independent static buffers for multiple file descriptors.

The branch contains the mandatory and bonus source/header pairs and helper functions. It has no Makefile and no test main, so it is a reusable source component rather than a standalone executable.

## Instructions

Choose a positive BUFFER_SIZE when compiling the implementation with a caller that provides main. For the mandatory version, compile get_next_line.c and get_next_line_utils.c and include get_next_line.h. For the bonus version, compile get_next_line_bonus.c and get_next_line_utils_bonus.c and include get_next_line_bonus.h.

A typical object compilation command is:

~~~sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line.c get_next_line_utils.c
~~~

Link those objects with a caller that reads from an open file descriptor. The caller is responsible for opening and closing the descriptor and freeing each returned line. No repository executable or Makefile target is available to run directly.

## Resources

- [POSIX read](https://pubs.opengroup.org/onlinepubs/9699919799/functions/read.html)
- [POSIX open](https://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html)
- [GNU C Library: dynamic memory](https://www.gnu.org/software/libc/manual/html_node/Unconstrained-Allocation.html)
- The 42 get_next_line subject is the reference for line boundaries, EOF, BUFFER_SIZE, and multi-descriptor behaviour.

### AI Usage

AI was used to inspect the buffer and static-storage logic, confirm that this branch has no Makefile or executable, and draft this README during the repository split. The implementation remains the checked-in source.

