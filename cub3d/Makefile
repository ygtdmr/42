# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/09/28 16:55:24 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror

SRC			=	cub3d.c \
				map_utils.c \
				parse_map.c \
				handle.c \
				cam.c \
				container.c \
				draw.c \
				render.c \
				str_list.c \
				str_utils.c \

OBJ			=	$(SRC:.c=.o)

GNL_SRC		=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

GNL_OBJ		=	$(GNL_SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(GNL_OBJ)
	@echo Compiling...
	@make -sC libft
	@make -sC minilibx-linux > /dev/null 2> /dev/null
	@$(CC) $(CFLAGS) $(OBJ) libft/libft.a minilibx-linux/libmlx.a -lm -lXext -lX11 $(GNL_OBJ) -lreadline -o $(NAME) > /dev/null
	@echo Done!

clean:
	@make clean -sC libft
	@$(RM) $(GNL_OBJ) $(OBJ)
	@echo Cleaned!

fclean:			clean
	@make fclean -sC libft
	@$(RM) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

re:				fclean all

bonus:

.PHONY:	all bonus clean fclean re
