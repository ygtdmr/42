*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 00

## Description

This branch contains the first C++ module: small C++98 exercises focused on namespaces, classes, member functions, standard input/output, initialization, and basic object design.

- ex00 builds megaphone, which uppercases the supplied arguments.
- ex01 implements an interactive fixed-size phonebook with Contact and PhoneBook classes.
- ex02 implements the Account class together with a small test program.

The code uses explicit constructors and class interfaces while staying within the C++98 language level required by the Makefiles.

## Instructions

A C++98 compiler and GNU Make are required. There is one Makefile per exercise; run commands from the repository root:

~~~sh
make -C ex00
make -C ex01
make -C ex02
~~~

Run the resulting programs with:

~~~sh
./ex00/megaphone "hello 42"
./ex01/phonebook
./ex02/tests
~~~

For the phonebook, enter the commands expected by the program, such as ADD, SEARCH, and EXIT. Each exercise supports all (the default), clean, fclean, and re; fclean removes its executable and object files.

## Resources

- [cppreference: C++ language](https://en.cppreference.com/w/cpp/language)
- [cppreference: iostream library](https://en.cppreference.com/w/cpp/io)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++98 standard library and the corresponding 42 C++ Module 00 subject were used as reference material.

### AI Usage

AI was used during this reorganization to inspect the source and Makefiles, draft this project-specific README, and check that its commands match the repository. The original exercise implementation is preserved; the README was reviewed against the checked-in files.

