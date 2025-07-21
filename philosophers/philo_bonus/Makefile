# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/07/21 12:32:27 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror

SRC			=	utils_1_bonus.c \
				utils_2_bonus.c \
				routine_bonus.c \
				philo_bonus.c \

all:			$(NAME)

$(NAME):		$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all bonus fclean re
