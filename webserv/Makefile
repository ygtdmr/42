# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/09 17:38:22 by yidemir           #+#    #+#              #
#    Updated: 2026/06/24 12:41:58 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	g++
CXXFLAGS	=	-g -Wall -Wextra -Werror -std=c++98

NAME		=	webserv

SRCS		=	main.cpp \
				test/debug.cpp \
				Tools.cpp \
				Config.cpp \
				Server.cpp \
				Client.cpp \
				Response.cpp

OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
