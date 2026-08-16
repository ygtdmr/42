*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 01

## Description

This branch contains exercises about memory allocation, references, pointers, object lifetime, file streams, and pointers to member functions.

- ex00 contrasts stack-created and heap-created Zombie objects.
- ex01 allocates and destroys a Zombie horde.
- ex02 demonstrates pointer and reference usage with a string.
- ex03 models Weapon, HumanA, and HumanB, including a reference-based weapon and a pointer-based weapon.
- ex04 performs string replacement in an input file and writes the result to a .replace file through FileManager.
- ex05 implements the Harl complaint levels.
- ex06 filters Harl messages by a requested level and emits the higher-severity messages.

All exercises are independent C++98 programs and use -Wall -Wextra -Werror -std=c++98.

## Instructions

Build an exercise from the repository root with its own Makefile:

~~~sh
make -C ex00
make -C ex01
make -C ex02
make -C ex03
make -C ex04
make -C ex05
make -C ex06
~~~

Run the generated executable in the matching directory. The executable names are zombie for ex00 and ex01, main for ex02 through ex05, and harlFilter for ex06. ex04 expects an input filename and replacement strings; ex06 expects a complaint level. Every exercise provides all, clean, fclean, and re targets.

## Resources

- [cppreference: dynamic storage duration](https://en.cppreference.com/w/cpp/language/storage_duration)
- [cppreference: references](https://en.cppreference.com/w/cpp/language/reference)
- [cppreference: file streams](https://en.cppreference.com/w/cpp/io)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++98 standard library and the C++ Module 01 subject are the primary references.

### AI Usage

AI was used during this reorganization to inspect the exercise sources, summarize the actual ownership and I/O patterns, and draft this README. No claim is made that AI generated the original implementation; the documentation was checked against the committed files.

