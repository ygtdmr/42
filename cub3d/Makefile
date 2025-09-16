# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/09/16 16:08:53 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			= 	gcc
CFLAGS		=	-g -Wall -Wextra -Werror

SRC			=	cub3d.c \
				map_utils.c \
				parse_map.c \
				str_list.c \
				str_utils.c

OBJ			=	$(SRC:.c=.o)

GNL_SRC		=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

GNL_OBJ		=	$(GNL_SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(GNL_OBJ)
	make -C libft
	make -C .minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a .minilibx-linux/libmlx.a -lXext -lX11 $(GNL_OBJ) -lreadline -o $(NAME)

clean:
	make clean -C libft
	$(RM) $(GNL_OBJ) $(OBJ)

fclean:			clean
	make fclean -C libft
	$(RM) $(NAME)

re:				fclean all

.PHONY:	all bonus clean fclean re
