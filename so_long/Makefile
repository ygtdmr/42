# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/03/15 15:49:14 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		so_long
CC		= 		cc
CFLAGS	=		-Wall -Wextra -Werror

SRC		=		lib/get_next_line/get_next_line.c \
				lib/get_next_line/get_next_line_utils.c \
				src/isvc.c \
				src/map_verify.c \
				src/map_verify_path.c \
				src/get_img.c \
				src/map_render.c \
				src/get_map.c \
				src/exit_sl.c \
				src/init_p.c \
				src/handle_keyhook.c \
				src/main.c

SRC_BONUS	=	lib/get_next_line/get_next_line.c \
				lib/get_next_line/get_next_line_utils.c \
				src/map_verify.c \
				src/map_verify_path.c \
				src/map_render.c \
				src/get_map.c \
				src/init_p.c \
				bonus/exit_sl_bonus.c \
				bonus/get_img_bonus.c \
				bonus/isvc_bonus.c \
				bonus/anim_bonus.c \
				bonus/enemy_bonus.c \
				bonus/handle_keyhook_bonus.c \
				bonus/main_bonus.c

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

all:		$(NAME)

$(NAME):	libft libmlx $(OBJ)
	$(CC) $(OBJ) lib/libft/libft.a lib/minilibx-linux/libmlx.a -lXext -lX11 -o $(NAME)

bonus:		libft libmlx $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) lib/libft/libft.a lib/minilibx-linux/libmlx.a -lXext -lX11 -o bonus/$(NAME)

libft:
	make -C lib/libft
	make bonus -C lib/libft

libmlx:
	if [ ! -d "lib/minilibx-linux" ]; then git clone https://github.com/42paris/minilibx-linux.git lib/minilibx-linux; fi
	make -C lib/minilibx-linux

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	make clean -C lib/libft

fclean:		clean
	$(RM) $(NAME)
	$(RM) bonus/$(NAME)
	make fclean -C lib/libft
	if [ -d "lib/minilibx-linux" ]; then make clean -C lib/minilibx-linux; fi

re:			fclean all

.PHONY:		all bonus clean fclean re
