# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/06/19 15:09:15 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		= 	cc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	minishell.c \
			env_list.c \
			lexer_utils.c \
			lexer.c \
			expand_utils.c \
			expand.c \
			parser_utils.c \
			parser.c \
			built_in.c \
			executer_utils.c \
			executer.c \
			test/print.c

all:		$(NAME)

$(NAME):	$(SRC)
	make -C libft
	# $(CC) $(SRC) libft/libft.a -L /usr/local/opt/readline/lib -I /usr/local/opt/readline/include -lreadline -o $(NAME) # for mac
	$(CC) $(SRC) libft/libft.a -lreadline -o $(NAME)

clean:
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft

re:		fclean all

.PHONY:	all bonus clean fclean re
