*This project has been created as part of the 42 curriculum by ygtdmr.*

# push_swap

## Description

push_swap sorts a sequence of integers using two linked-list stacks, A and B, while emitting stack operations. The implementation parses and validates the arguments, handles duplicate/error cases, sorts small stacks with targeted operations, and uses separate movement helpers for larger inputs.

The bonus checker reads operations from standard input, applies valid actions to the two stacks, and prints OK when the final state is sorted with an empty B stack, or KO otherwise. A small copy of the required libft routines is kept under src/libft because the project Makefile links those sources directly.

## Instructions

Build the mandatory program and, when needed, the checker:

~~~sh
make
make bonus
~~~

Generate operations for a sample input:

~~~sh
./push_swap 3 2 1
~~~

Check an operation sequence by piping it to the bonus checker:

~~~sh
printf "sa\n" | ./checker 2 1 3
~~~

The Makefile provides all, bonus, clean, fclean, and re. The checker accepts the stack-operation input used by the project, including commands such as sa, pb, pa, ra, and rra.

## Resources

- [POSIX write](https://pubs.opengroup.org/onlinepubs/9699919799/functions/write.html)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- The 42 push_swap subject is the reference for the two-stack operation set and checker protocol.
- Linked-list and sorting references were used to reason about the stack helpers and movement strategy.

### AI Usage

AI was used to inspect the stack representation, parser, operation dispatcher, and Makefile, verify the documented sample commands, and draft this README during the branch split. The sorting implementation remains the checked-in code.

