*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 04

## Description

This branch explores subtype polymorphism, abstract interfaces, deep copying, and interface-based object ownership.

- ex00 contrasts virtual and non-virtual dispatch with Animal, Cat, Dog, WrongAnimal, and WrongCat.
- ex01 adds Brain objects and tests deep copies for Cat and Dog.
- ex02 extends the same hierarchy and ownership model with another deep-copy exercise.
- ex03 defines the AMateria, ICharacter, and IMateriaSource interfaces, concrete Ice and Cure materia, a character inventory, and a materia source.

The projects are separate C++98 exercises and use virtual functions, virtual destructors, cloning, and explicit resource management where the source implements them.

## Instructions

Build each exercise independently:

~~~sh
make -C ex00
make -C ex01
make -C ex02
make -C ex03
~~~

Run ./ex00/main, ./ex01/main, ./ex02/main, or ./ex03/main after building. Each Makefile supports all, clean, fclean, and re; no external library is configured.

## Resources

- [cppreference: virtual functions](https://en.cppreference.com/w/cpp/language/virtual)
- [cppreference: abstract classes](https://en.cppreference.com/w/cpp/language/abstract_class)
- [cppreference: copy constructors](https://en.cppreference.com/w/cpp/language/copy_constructor)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++ Module 04 subject is the reference for the animal and materia interfaces.

### AI Usage

AI was used during this repository task to inspect the actual class definitions, describe the ownership and polymorphism present, and draft the README. The implementation remains the original checked-in code; the description was checked against the source tree.

