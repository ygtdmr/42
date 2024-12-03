# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2024/12/02 12:04:25 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc

SRC =	ft_ispf.c \
		ft_ispfe_bonus.c \
		ft_isprint.c \
		ft_printf.c \
		ft_putbase.c \
		ft_putchr.c \
		ft_putldbl.c \
		ft_putf.c \
		ft_putllong.c \
		ft_putptr.c \
		ft_putint.c \
		ft_putsci.c \
		ft_putsciordbl.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strncmp.c

OBJ = $(SRC:.c=.o)

#BONUS_SRC = test.c \

#BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

#bonus: $(BONUS_OBJ)
#	$(AR) $(NAME) $(BONUS_OBJ)
	
clean:
	$(RM) $(OBJ)
#	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
