# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2025/02/21 14:05:01 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc

SRC =		src/libft/ft_strlen.c \
			src/libft/ft_strlcpy.c \
			src/libft/ft_memset.c \
			src/libft/ft_bzero.c \
			src/libft/ft_strchr.c \
			src/libft/ft_strnstr.c \
			src/libft/ft_atoi.c \
			src/libft/ft_calloc.c \
			src/libft/ft_strdup.c \
			src/libft/ft_split.c \
			src/libft/ft_itoa.c \
			src/stack_add_back.c \
			src/stack_add_front.c \
			src/stack_clear.c \
			src/stack_delone.c \
			src/stack_last.c \
			src/stack_new.c \
			src/stack_size.c \
			src/stack_sorted.c \
			src/args_to_list.c \
			src/stack_action.c \
			src/do_action.c \
			src/nbr_next.c \
			src/nbr_prev.c \
			src/nbr_max.c \
			src/nbr_mv_side.c \
			src/nbr_mv.c \
			src/nbr_set.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME).a $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).c $(NAME).a
	$(RM) $(NAME).a

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(NAME).a

re: fclean all

.PHONY: all bonus clean fclean re
