# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2024/12/08 10:35:22 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc

SRC =	ft_base.c \
		ft_baseptr.c \
		ft_ispformat.c \
		ft_ispflag.c \
		ft_rpformat.c \
		ft_printf.c \
		libft/ft_atoi.c \
		libft/ft_strlen.c \
		libft/ft_bzero.c \
		libft/ft_strncmp.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_itoa.c \
		libft/ft_strjoin.c \
		libft/ft_memset.c \
		libft/ft_strchr.c \
		libft/ft_isdigit.c \
		libft/ft_substr.c \
		ft_rpflag_bonus.c \
		ft_getpflag_bonus.c \
		ft_strjcf_bonus.c \

OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_rpflag_bonus.c \
			ft_getpflag_bonus.c \
			ft_strjcf_bonus.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: all
#	$(AR) $(NAME) $(BONUS_OBJ)
	
clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
