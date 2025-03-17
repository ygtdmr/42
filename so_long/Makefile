# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/03/17 14:16:26 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		so_long
CC		= 		cc
CFLAGS	=		-Wall -Wextra -Werror

SRC		=		get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				isvc.c \
				map_verify.c \
				map_verify_path.c \
				get_img.c \
				map_render.c \
				get_map.c \
				exit_sl.c \
				init_p.c \
				handle_keyhook.c \
				main.c

SRC_BONUS	=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				map_verify.c \
				map_verify_path.c \
				map_render.c \
				get_map.c \
				init_p.c \
				bonus/exit_sl_bonus.c \
				bonus/get_img_bonus.c \
				bonus/isvc_bonus.c \
				bonus/anim_bonus.c \
				bonus/enemy_bonus.c \
				bonus/handle_keyhook_bonus.c \
				bonus/main_bonus.c

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

all:			$(NAME)

# $(NAME):		$(OBJ)
# 	make -C libft && make -C minilibx-linux
# 	$(CC) $(OBJ) libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -o $(NAME)

$(NAME):		$(OBJ)
	make -C libft && make -C minilibx-linux
	$(CC) $(OBJ) libft/libft.a minilibx-linux/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

bonus:			bonus/$(NAME)

# bonus/$(NAME):	$(OBJ_BONUS)
# 	make all bonus -C libft && make -C minilibx-linux
# 	$(CC) $(OBJ_BONUS) libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -o bonus/$(NAME)

bonus/$(NAME):	$(OBJ_BONUS)
	make all bonus -C libft && make -C minilibx-linux
	$(CC) $(OBJ_BONUS) libft/libft.a minilibx-linux/libmlx.a -framework OpenGL -framework AppKit -o bonus/$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	make clean -C libft

fclean:		clean
	$(RM) $(NAME)
	$(RM) bonus/$(NAME)
	make fclean -C libft
	make clean -C minilibx-linux

re:			fclean all

.PHONY:		all bonus clean fclean re
