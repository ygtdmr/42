*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 02

## Description

This branch studies canonical fixed-point arithmetic and operator overloading in C++98.

- ex00 introduces a Fixed class with a raw integer value and eight fractional bits.
- ex01 adds integer and floating-point conversions, comparison operators, increment/decrement operators, and arithmetic operators.
- ex02 adds the min/max helpers and exercises the richer Fixed interface.
- ex03 adds Point and the bsp function to determine whether a point lies inside a triangle.

The four exercises are separate programs. Their Makefiles compile with c++ -Wall -Wextra -Werror -std=c++98.

## Instructions

Build each exercise independently:

~~~sh
make -C ex00
make -C ex01
make -C ex02
make -C ex03
~~~

The executable produced by every exercise is main in that exercise directory:

~~~sh
./ex00/main
./ex01/main
./ex02/main
./ex03/main
~~~

Each Makefile supports all, clean, fclean, and re. No external library is required.

## Resources

- [cppreference: operator overloading](https://en.cppreference.com/w/cpp/language/operators)
- [cppreference: user-defined conversions](https://en.cppreference.com/w/cpp/language/cast_operator)
- [cppreference: floating-point types](https://en.cppreference.com/w/cpp/language/types)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++98 standard library and the C++ Module 02 subject provide the fixed-point and geometry requirements.

### AI Usage

AI was used during this reorganization to inspect the Fixed and Point implementations, verify the documented build commands, and draft this README. The implementation itself remains the checked-in project code and the documentation was reviewed against it.

