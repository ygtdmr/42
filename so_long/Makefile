# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/03/06 17:08:33 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	lib/get_next_line/get_next_line.c \
		lib/get_next_line/get_next_line_utils.c \
		src/main.c \
		src/map_verify.c \
		src/map_render.c \
		src/get_map.c \
		src/handle_keyhook.c \
		src/exit_sl.c \
		src/init_pc.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) lib/libft/libft.a $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) lib/libft/libft.a lib/mlx/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
