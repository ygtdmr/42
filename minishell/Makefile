# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/05/04 14:18:05 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		= 	cc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	minishell.c \
			add_history.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C libft
	$(CC) $(OBJ) libft/libft.a -lreadline -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft

re:		fclean all

.PHONY:	all bonus clean fclean re
