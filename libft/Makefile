# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2024/10/31 22:40:06 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

BONUS_SRC = $(shell find ft_lst*.c)
BONUS_OBJ = $(patsubst %.c, %.o, $(BONUS_SRC))

SRC = $(shell find ft_*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
NAME = libft.a

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

bonus:	
	$(CC) $(FLAGS) -c $(BONUS_SRC)
	ar -rcs $(NAME) $(BONUS_OBJ)
re: clean fclean all

clean:
	rm -f $(shell find ft_*.o)

fclean:
	rm -f $(NAME)
