# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:33:55 by yigit             #+#    #+#              #
#    Updated: 2025/01/26 20:40:23 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

all: server client

bonus: server_bonus client_bonus

server: server.c minitalk.h
	$(CC) $(CFLAGS) -o server server.c

client: client.c minitalk.h
	$(CC) $(CFLAGS) -o client client.c

server_bonus: server_bonus.c minitalk.h
	$(CC) $(CFLAGS) -o server server_bonus.c

client_bonus: client_bonus.c minitalk_bonus.h
	$(CC) $(CFLAGS) -o client client_bonus.c

clean:
	$(RM) server client

fclean: clean

re: fclean all

.PHONY: all $(NAME) clean fclean re
