*This project has been created as part of the 42 curriculum by ygtdmr.*

# libft

## Description

libft is a static C library that recreates the core libc string, character, memory, conversion, and file-descriptor output helpers required by the 42 curriculum. The branch also contains the linked-list bonus API, including creation, insertion, iteration, mapping, and cleanup functions. The implementation is self-contained and exposes its public declarations through libft.h.

## Instructions

A C compiler and GNU Make are required. Build the mandatory archive with:

~~~sh
make
~~~

Build the linked-list bonus objects into the same archive with:

~~~sh
make bonus
~~~

The Makefile uses cc -Wall -Wextra -Werror and provides all, bonus, clean, fclean, and re. The result is libft.a; this branch does not include a standalone executable or test main. A caller can include libft.h and link with cc caller.c -L. -lft.

## Resources

- [The C standard library reference](https://en.cppreference.com/w/c)
- [POSIX functions](https://pubs.opengroup.org/onlinepubs/9699919799/)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The 42 Libft subject is the reference for required function behaviour and bonus list helpers.

### AI Usage

AI was used during this repository reorganization to inspect the function inventory and Makefile, verify the documented targets, and draft this README. The library implementation remains the checked-in project code.
