# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2024/12/04 23:46:39 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc

SRC =	ft_base.c \
		ft_baseptr.c \
		ft_ispf.c \
		ft_renderf.c \
		ft_printf.c \
		libft/ft_strlen.c \
		libft/ft_bzero.c \
		libft/ft_strncmp.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_itoa.c \
		libft/ft_strjoin.c \
		libft/ft_memset.c \

OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_ispfe_bonus.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

#bonus: $(BONUS_OBJ)
#	$(AR) $(NAME) $(BONUS_OBJ)
	
clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
