# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/07/28 06:21:05 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
CC			= 	gcc
CFLAGS		=	-g -Wall -Wextra -Werror

SRC			=	minishell.c \
				str_utils.c \
				lexer_utils.c \
				lexer.c \
				expand_utils.c \
				expand.c \
				redir_utils.c \
				heredoc.c \
				parser_utils.c \
				parser.c \
				env_utils_1.c \
				env_utils_2.c \
				built_in_utils.c \
				built_in_1.c \
				built_in_2.c \
				executer_utils.c \
				executer.c \
				.test/print.c #	after testing you should remove this.

OBJ			=	$(SRC:.c=.o)

GNL_SRC		=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

GNL_OBJ		=	$(GNL_SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(GNL_OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) libft/libft.a -lreadline -o $(NAME)

clean:
	make clean -C libft
	$(RM) $(OBJ) $(GNL_OBJ)

fclean:			clean
	make fclean -C libft
	$(RM) $(NAME)

re:				fclean all

.PHONY:	all bonus clean fclean re
