*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 03

## Description

This branch focuses on inheritance and protected state through a family of combat-oriented classes.

- ex00 implements the base ClapTrap.
- ex01 derives ScavTrap from ClapTrap.
- ex02 adds FragTrap and exercises multiple derived behaviours.
- ex03 combines the hierarchy in DiamondTrap, including inherited members and name handling.

The exercises demonstrate constructors and destructors, inheritance, method reuse, and the effect of shared base-class state. Each exercise is an independent C++98 program.

## Instructions

Build an exercise from the repository root:

~~~sh
make -C ex00
make -C ex01
make -C ex02
make -C ex03
~~~

Run the resulting executable with ./ex00/main, ./ex01/main, ./ex02/main, or ./ex03/main. Every exercise Makefile supports all, clean, fclean, and re. Compilation uses c++ -Wall -Wextra -Werror -std=c++98.

## Resources

- [cppreference: derived classes](https://en.cppreference.com/w/cpp/language/derived_class)
- [cppreference: virtual functions](https://en.cppreference.com/w/cpp/language/virtual)
- [cppreference: constructors and destructors](https://en.cppreference.com/w/cpp/language/initializer_list)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++ Module 03 subject is the reference for the ClapTrap, ScavTrap, FragTrap, and DiamondTrap progression.

### AI Usage

AI was used to inspect the class hierarchy and Makefiles while preparing this branch documentation. It helped summarize the concepts and verify commands; the original source was not replaced or represented as AI-generated.

