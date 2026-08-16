*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 07

## Description

This branch introduces function and class templates.

- ex00 implements a generic whatever-style swap, min, and max exercise.
- ex01 implements iter, applying a callable operation to each element of an array.
- ex02 implements a templated Array class with dynamic storage, indexing, size reporting, and copy behaviour.

The three exercises are separate C++98 programs and rely only on the standard language and library.

## Instructions

Build the exercises independently:

~~~sh
make -C ex00
make -C ex01
make -C ex02
~~~

Run ./ex00/main, ./ex01/main, or ./ex02/main. The Makefiles use c++ -Wall -Wextra -Werror -std=c++98 and provide all, clean, fclean, and re targets.

## Resources

- [cppreference: function templates](https://en.cppreference.com/w/cpp/language/function_template)
- [cppreference: class templates](https://en.cppreference.com/w/cpp/language/class_template)
- [cppreference: copy constructors](https://en.cppreference.com/w/cpp/language/copy_constructor)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++ Module 07 subject is the reference for the template interfaces implemented here.

### AI Usage

AI was used to inspect the template headers and tests, verify the per-exercise commands, and draft this README as part of the repository split. The original implementation was retained and the documentation was checked against it.

