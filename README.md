*This project has been created as part of the 42 curriculum by ygtdmr.*

# C++ Module 09

## Description

This branch contains three C++98 exercises built around standard containers, parsing, validation, and algorithm design.

- ex00 builds btc. BitcoinExchange loads a local data.csv file, validates dates and amounts, and calculates the exchange value for each input line.
- ex01 builds RPN, evaluating a reverse Polish notation expression with a stack and reporting invalid expressions.
- ex02 builds PmergeMe, parsing positive integers and sorting them with a Ford-Johnson-style merge-insertion algorithm using both vector and deque while reporting timing information.

The source tree currently contains the programs and their Makefiles, but no data.csv or sample input file. ex00 therefore requires the user to provide the expected data file beside the executable's working directory.

## Instructions

Build each exercise independently:

~~~sh
make -C ex00
make -C ex01
make -C ex02
~~~

Run ex01 and ex02 with the arguments shown below:

~~~sh
./ex01/RPN "8 9 + 2 *"
./ex02/PmergeMe 3 5 9 7 4
~~~

Run ex00 from ex00 with a data.csv file beside the executable and an input file whose first line is date | value:

~~~sh
(cd ex00 && ./btc input.txt)
~~~

The data file must begin with date,exchange_rate. Each exercise Makefile uses c++ -Wall -Wextra -Werror -std=c++98 and supports all, clean, fclean, and re. The programs print Error for invalid input according to their implemented checks.

## Resources

- [cppreference: std::map](https://en.cppreference.com/w/cpp/container/map)
- [cppreference: std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [cppreference: std::vector and std::deque](https://en.cppreference.com/w/cpp/container/vector)
- [cppreference: algorithms](https://en.cppreference.com/w/cpp/algorithm)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The C++ Module 09 subject is the reference for the exchange, RPN, and merge-insertion exercises.

### AI Usage

AI was used during this repository task to inspect the parsers and container algorithms, identify the missing ex00 runtime data dependency, verify the documented build commands, and draft this README. The code and data files were not claimed to be AI-generated.

