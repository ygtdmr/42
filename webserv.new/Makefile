# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/09 17:38:22 by yidemir           #+#    #+#              #
#    Updated: 2026/07/08 09:15:44 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	g++
CXXFLAGS	=	-g -Wall -Wextra -Werror -std=c++98 -Wparentheses # DELETE AFTER DEVELOP (-Wparentheses)

NAME		=	webserv

SRCS		=	src/main.cpp \
				src/parser/statusToReasonPhrase.cpp \
				src/parser/Config/parseStateGlobal.cpp \
				src/parser/Config/putDataLocation.cpp \
				src/parser/Config/parseStateServer.cpp \
				src/parser/Config/parse.cpp \
				src/parser/Config/isValidServerName.cpp \
				src/parser/Config/getServers.cpp \
				src/parser/Config/printServers.cpp \
				src/parser/Config/isValidDigit.cpp \
				src/parser/Config/parseStateLocation.cpp \
				src/parser/Config/putRaw.cpp \
				src/parser/Config/putDataServer.cpp \
				src/parser/Config/Config.cpp \
				src/parser/Config/isValidPath.cpp \
				src/parser/Config/isValidIPv4.cpp \
				src/parser/Config/validateLocation.cpp \
				src/parser/Config/validateServer.cpp \
				src/parser/Config/isValidMethod.cpp \
				src/parser/unchunkBody.cpp \
				src/parser/fileExt.cpp \
				src/parser/mapToHeaders.cpp \
				src/parser/Request/parseFirstLine.cpp \
				src/parser/Request/parse.cpp \
				src/parser/Request/Request.cpp \
				src/parser/Request/parseLocation.cpp \
				src/parser/Request/parseBody.cpp \
				src/parser/Request/parseChunkedBody.cpp \
				src/parser/Request/parseHeaders.cpp \
				src/parser/Request/checkMaxBodySize.cpp \
				src/parser/extToMimeType.cpp \
				src/parser/headersToMap.cpp \
				src/parser/mimeTypeToExt.cpp \
				src/parser/handler.cpp \
				src/Controller/acceptConnection.cpp \
				src/Controller/newConnection.cpp \
				src/Controller/run.cpp \
				src/Controller/setup.cpp \
				src/Controller/setupServer.cpp \
				src/Controller/clear.cpp \
				src/Controller/Controller.cpp \
				src/Controller/closeConnection.cpp \
				src/manager/Manager.cpp \
				src/manager/Client/process.cpp \
				src/manager/Client/Client.cpp \
				src/manager/Client/clear.cpp \
				src/manager/Client/deliver.cpp \
				src/manager/Client/receive.cpp \
				src/manager/Server.cpp \
				src/http/handler/Redirection/Redirection.cpp \
				src/http/handler/Redirection/build.cpp \
				src/http/handler/Get/buildBody.cpp \
				src/http/handler/Get/buildHeaders.cpp \
				src/http/handler/Get/build.cpp \
				src/http/handler/Get/Get.cpp \
				src/http/handler/DirectoryListing/DirectoryListing.cpp \
				src/http/handler/DirectoryListing/build.cpp \
				src/http/handler/Handler.cpp \
				src/http/handler/Error/readErrorPageFile.cpp \
				src/http/handler/Error/Error.cpp \
				src/http/handler/Error/buildBody.cpp \
				src/http/handler/Error/buildHeaders.cpp \
				src/http/handler/Error/build.cpp \
				src/http/Message.cpp \
				src/http/Exception.cpp \
				src/http/Request.cpp \
				src/http/Response/Response.cpp \
				src/http/Response/getFirstLine.cpp 



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
