# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/07/23 11:36:56 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror

SRC			=	utils_1.c \
				utils_2.c \
				utils_3.c \
				routine.c \
				monitor.c \
				philo.c \

all:			$(NAME)

$(NAME):		$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all bonus fclean re
