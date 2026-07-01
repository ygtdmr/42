# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/09 17:38:22 by yidemir           #+#    #+#              #
#    Updated: 2026/07/01 20:10:49 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	g++
CXXFLAGS	=	-g -Wall -Wextra -Werror -std=c++98 -Wparentheses # DELETE AFTER DEVELOP (-Wparentheses)

NAME		=	webserv

SRCS		=	src/main.cpp \
				src/parser/Config/Config.cpp \
				src/parser/Config/getServers.cpp \
				src/parser/Config/printServers.cpp \
				src/parser/Config/isValidDigit.cpp \
				src/parser/Config/isValidIPv4.cpp \
				src/parser/Config/isValidPath.cpp \
				src/parser/Config/isValidMethod.cpp \
				src/parser/Config/isValidServerName.cpp \
				src/parser/Config/parse.cpp \
				src/parser/Config/parseStateGlobal.cpp \
				src/parser/Config/parseStateLocation.cpp \
				src/parser/Config/parseStateServer.cpp \
				src/parser/Config/putDataLocation.cpp \
				src/parser/Config/putDataServer.cpp \
				src/parser/Config/putRaw.cpp \
				src/parser/Config/validateLocation.cpp \
				src/parser/Config/validateServer.cpp


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
