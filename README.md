*This project has been created as part of the 42 curriculum by ygtdmr.*

# ft_printf

## Description

ft_printf is a small printf-like C library. The exported ft_printf function uses variadic arguments and formats characters, strings, pointers, signed integers, unsigned integers, hexadecimal integers, and literal percent signs. The implementation is split into conversion-specific writers and returns the number of characters written, or -1 when a write fails.

The repository builds the static archive libftprintf.a from the files at the branch root. It has no executable or bundled test main.

## Instructions

A C compiler and GNU Make are required:

~~~sh
make
~~~

The Makefile uses cc -Wall -Wextra -Werror. The available targets are all (the default archive build), clean, fclean, and re. To use the library, include ft_printf.h and link libftprintf.a with a caller, for example:

~~~sh
cc -Wall -Wextra -Werror caller.c -L. -lftprintf -o caller
~~~

The final link command above assumes caller.c supplies main and calls ft_printf.

## Resources

- [cppreference: variadic arguments](https://en.cppreference.com/w/c/variadic)
- [POSIX write](https://pubs.opengroup.org/onlinepubs/9699919799/functions/write.html)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The printf specification and the 42 ft_printf subject are the primary behavioural references.

### AI Usage

AI was used during this repository reorganization to inspect the conversion dispatch and Makefile, draft this README, and verify that no standalone executable is provided. The library source remains the checked-in implementation.

