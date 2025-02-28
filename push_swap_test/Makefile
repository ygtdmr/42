# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2025/02/24 22:18:57 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_BONUS =	bonus/checker_bonus.c \
			bonus/checker_utils_bonus.c

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
			src/stack_action.c \
			src/args_to_list.c \
			src/do_action.c \
			src/nbr_next.c \
			src/nbr_prev.c \
			src/nbr_max.c \
			src/nbr_mv_side.c \
			src/nbr_mv.c \
			src/nbr_set.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(NAME).c
	$(CC) $(CFLAGS) $(OBJ) $(NAME).c -o $(NAME)

$(NAME_BONUS): $(OBJ) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
