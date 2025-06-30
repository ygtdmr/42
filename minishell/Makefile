# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/06/30 16:20:54 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		= 	cc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	minishell.c \
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
			built_in_1.c \
			built_in_2.c \
			executer_utils.c \
			executer.c \

GNL_SRC	=	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

all:		$(NAME)

$(NAME):	$(SRC)
	make -C libft
	$(CC) $(SRC) $(GNL_SRC) libft/libft.a -lreadline -o $(NAME)

clean:
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft

re:		fclean all

.PHONY:	all bonus clean fclean re
