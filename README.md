*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 05

## Description

This branch introduces exception handling and increasingly structured form workflows.

- ex00 implements Bureaucrat with grade bounds and exceptions.
- ex01 adds Form, signature requirements, and execution eligibility.
- ex02 introduces the abstract AForm hierarchy with ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm.
- ex03 adds Intern, which creates concrete forms from a requested form name.

The exercises use C++98 classes, inheritance, exception types, and polymorphic form execution. Each directory is an independent executable with its own Makefile.

## Instructions

Build from the repository root:

~~~sh
make -C ex00
make -C ex01
make -C ex02
make -C ex03
~~~

Run the executable in the exercise directory with ./ex00/main, ./ex01/main, ./ex02/main, or ./ex03/main. The Makefiles use c++ -Wall -Wextra -Werror -std=c++98 and provide all, clean, fclean, and re targets. The test inputs are defined in each exercise's main.cpp, so the programs do not require an external configuration file.

## Resources

- [cppreference: exceptions](https://en.cppreference.com/w/cpp/language/exceptions)
- [cppreference: inheritance](https://en.cppreference.com/w/cpp/language/derived_class)
- [cppreference: virtual functions](https://en.cppreference.com/w/cpp/language/virtual)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++ Module 05 subject is the reference for Bureaucrat, Form, AForm, concrete forms, and Intern.

### AI Usage

AI was used to inspect the actual exception and form classes, verify the per-exercise build commands, and draft this README during the repository reorganization. The implementation remains the checked-in project code and was not represented as AI-generated.

