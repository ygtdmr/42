# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2024/10/24 13:41:01 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = $(shell find ft_*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
NAME = libft.a

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -r $(NAME) $(OBJ)

all: $(NAME)

re: clean fclean all

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)