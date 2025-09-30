# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/09/27 15:50:22 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			= 	gcc
CFLAGS		=	-g -Wall -Wextra -Werror

SRC			=	cub3d.c \
				map_utils.c \
				parse_map.c \
				img_utils.c \
				render.c \
				handle.c \
				str_list.c \
				str_utils.c \
				.test/test.c #delete this line before production \

OBJ			=	$(SRC:.c=.o)

GNL_SRC		=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

GNL_OBJ		=	$(GNL_SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(GNL_OBJ)
	make -C libft
	make -C .minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a .minilibx-linux/libmlx.a -lm -lXext -lX11 $(GNL_OBJ) -lreadline -o $(NAME)

clean:
	make clean -C libft
	$(RM) $(GNL_OBJ) $(OBJ)

fclean:			clean
	make fclean -C libft
	$(RM) $(NAME)

re:				fclean all

.PHONY:	all bonus clean fclean re
