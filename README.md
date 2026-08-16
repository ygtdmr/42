*This project has been created as part of the 42 curriculum by ygtdmr, iarslan.*

# minishell

## Description

minishell is an interactive POSIX-like shell written in C. The mandatory implementation lexes command lines, handles quotes and environment expansion, builds command and redirection structures, executes pipelines and external programs, supports heredocs, and implements shell builtins.

The mandatory tree contains echo, cd, pwd, export, unset, env, and exit builtins, input/output/append/error redirections, pipes, signal handling, and a vendored libft plus get_next_line implementation. The bonus tree adds wildcard expansion, operators, and sub-shell-oriented parsing/execution helpers.

## Instructions

A C compiler, GNU Make, and the readline development library are required:

~~~sh
make
./minishell
~~~

The Makefile also provides:

~~~sh
make bonus
./minishell_bonus
make clean
make fclean
make re
~~~

Use ordinary shell syntax supported by the implementation, for example pipelines and redirections. A heredoc is written with two less-than signs followed by a delimiter. The program can also be used non-interactively by piping input into it. The shell inherits the environment of its parent process and uses readline for the interactive prompt.

## Known Build Issue

On the current macOS system readline headers, the mandatory build stops because `rl_replace_line` and `rl_clear_history` are not declared by the installed header set. This is an existing portability/toolchain issue in the checked-in source and was not changed during the split. The Makefile command above is the intended build on a compatible readline installation.

## Resources

- [POSIX Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)
- [POSIX process creation](https://pubs.opengroup.org/onlinepubs/9699919799/functions/fork.html)
- [POSIX pipe](https://pubs.opengroup.org/onlinepubs/9699919799/functions/pipe.html)
- [GNU Readline manual](https://tiswww.case.edu/php/chet/readline/rltop.html)
- The 42 minishell subject is the reference for the required shell grammar, builtins, signals, and execution behaviour.

### AI Usage

AI was used during this repository reorganization to inspect the lexer, parser, expansion, redirection, builtin, and executor sources; verify the Makefile targets and dependencies; and draft this README. The shell implementation remains the checked-in project code.
