# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2024/12/15 16:03:02 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgetnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1000000
AR = ar -rc

SRC =	get_next_line.c \
		get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
