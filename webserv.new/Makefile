# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/09 17:38:22 by yidemir           #+#    #+#              #
#    Updated: 2026/06/30 13:15:32 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	g++
CXXFLAGS	=	-g -Wall -Wextra -Werror -std=c++98 -Wparentheses # DELETE AFTER DEVELOP (-Wparentheses)

NAME		=	webserv

SRCS		=	src/main.cpp \
				src/ServerConfig.cpp \
				src/ConfigParser.cpp \
				src/ServerManager.cpp \
				src/Client.cpp \
				src/HttpConversion.cpp \
				src/HttpRequest.cpp \
				src/HttpResponse.cpp

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
