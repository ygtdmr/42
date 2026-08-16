*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 06

## Description

This branch studies explicit C++ casts, scalar conversion, serialization, and runtime type identification.

- ex00 implements ScalarConverter, which parses a string literal and prints conversions to char, int, float, and double.
- ex01 implements Serializer, converting a Data pointer to an integer representation and back.
- ex02 defines a polymorphic Base hierarchy and identifies whether a runtime object is an A, B, or C instance.

These are independent C++98 exercises. Their Makefiles use -Wall -Wextra -Werror -std=c++98.

## Instructions

Build and run the exercises as follows:

~~~sh
make -C ex00
make -C ex01
make -C ex02
./ex00/convert 42
./ex01/main
./ex02/main
~~~

ex00 takes one literal argument; the other two exercises use the test cases compiled into their main.cpp files. Each Makefile supports all, clean, fclean, and re.

## Resources

- [cppreference: explicit type conversions](https://en.cppreference.com/w/cpp/language/explicit_cast)
- [cppreference: reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast)
- [cppreference: type identification](https://en.cppreference.com/w/cpp/language/typeid)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++ Module 06 subject is the reference for scalar conversion, serialization, and RTTI exercises.

### AI Usage

AI was used during this task to inspect ScalarConverter, Serializer, and the Base hierarchy, validate the documented commands, and draft the README. The source implementation remains the original checked-in work.

