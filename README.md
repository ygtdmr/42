*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 08

## Description

This branch applies the C++ Standard Template Library to generic algorithms and containers.

- ex00 implements easyfind for searching an integer value in a standard container.
- ex01 implements Span, including number insertion and shortest/longest span calculations.
- ex02 implements MutantStack, exposing iterators on top of a stack-like container.

The exercises are independent C++98 programs and use standard containers and iterators rather than external dependencies.

## Instructions

Build and run each exercise:

~~~sh
make -C ex00
make -C ex01
make -C ex02
./ex00/main
./ex01/main
./ex02/main
~~~

Each Makefile uses c++ -Wall -Wextra -Werror -std=c++98 and supports all, clean, fclean, and re.

## Resources

- [cppreference: containers](https://en.cppreference.com/w/cpp/container)
- [cppreference: iterators](https://en.cppreference.com/w/cpp/iterator)
- [cppreference: algorithms](https://en.cppreference.com/w/cpp/algorithm)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++ Module 08 subject is the reference for easyfind, Span, and MutantStack.

### AI Usage

AI was used during this reorganization to inspect the STL usage and test programs, validate the build instructions, and draft this project-specific README. The implementation remains the checked-in source.

