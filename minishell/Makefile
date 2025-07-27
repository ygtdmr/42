# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/07/23 21:04:47 by iarslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
NAME_BONUS	=	minishell_bonus
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror

SRC			=	minishell.c \
				str_utils.c \
				lexer_utils.c \
				lexer.c \
				expand_utils.c \
				expand.c \
				redir_utils.c \
				parser_utils.c \
				parser.c \
				env_utils_1.c \
				env_utils_2.c \
				built_in_utils.c \
				built_in_1.c \
				built_in_2.c \
				executer_utils.c \
				executer.c \
				.test/print.c \

SRC_BONUS	=	bonus/minishell_bonus.c \
				bonus/str_utils_bonus.c \
				bonus/lexer_utils_bonus.c \
				bonus/lexer_bonus.c \
				bonus/expand_utils_bonus.c \
				bonus/expand_bonus.c \
				bonus/redir_utils_bonus.c \
				bonus/parser_utils_bonus.c \
				bonus/parser_bonus.c \
				bonus/env_utils_1_bonus.c \
				bonus/env_utils_2_bonus.c \
				bonus/built_in_utils_bonus.c \
				bonus/built_in_1_bonus.c \
				bonus/built_in_2_bonus.c \
				bonus/executer_utils_bonus.c \
				bonus/executer_bonus.c \
				bonus/willcard_bonus.c \
				bonus/subshell_bonus.c \
				bonus/.test/print_bonus.c \

GNL_SRC	=	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(SRC)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) $(GNL_SRC) libft/libft.a -lreadline -o $(NAME)

$(NAME_BONUS):	$(SRC_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(SRC_BONUS) $(GNL_SRC) libft/libft.a -lreadline -o $(NAME_BONUS)

clean:
	make clean -C libft

fclean:	clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C libft

re:		fclean all

.PHONY:	all bonus clean fclean re
