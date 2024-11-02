# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2024/11/02 14:01:15 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar -rcs
RM = rm -f
FLAGS = -Wall -Wextra -Werror

BONUS_SRC = $(shell find ft_lst*.c)
BONUS_OBJ = $(patsubst %.c, %.o, $(BONUS_SRC))

SRC = $(shell find ft_*.c ! -name "ft_lst*.c")
OBJ = $(patsubst %.c, %.o, $(SRC))
NAME = libft.a

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

all: $(NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
