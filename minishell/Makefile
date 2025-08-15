# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:51:02 by yidemir           #+#    #+#              #
#    Updated: 2025/08/14 15:03:30 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
NAME_BONUS	=	minishell_bonus
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror

SRC			=	minishell.c \
				minishell_utils.c \
				str_utils_1.c \
				str_utils_2.c \
				lexer_utils.c \
				lexer.c \
				expand_utils.c \
				expand.c \
				redir_utils.c \
				heredoc.c \
				parser_utils.c \
				parser.c \
				env_utils_1.c \
				env_utils_2.c \
				built_in_utils.c \
				built_in_1.c \
				built_in_2.c \
				executer_utils.c \
				executer.c \

SRC_BONUS	=	bonus/minishell_bonus.c \
				bonus/minishell_utils_bonus.c \
				bonus/str_utils_1_bonus.c \
				bonus/str_utils_2_bonus.c \
				bonus/lexer_utils_bonus.c \
				bonus/lexer_bonus.c \
				bonus/expand_utils_bonus.c \
				bonus/expand_bonus.c \
				bonus/redir_utils_1_bonus.c \
				bonus/redir_utils_2_bonus.c \
				bonus/heredoc_bonus.c \
				bonus/parser_utils_bonus.c \
				bonus/parser_bonus.c \
				bonus/env_utils_1_bonus.c \
				bonus/env_utils_2_bonus.c \
				bonus/built_in_utils_bonus.c \
				bonus/built_in_1_bonus.c \
				bonus/built_in_2_bonus.c \
				bonus/executer_utils_bonus.c \
				bonus/executer_bonus.c \
				bonus/subsh_bonus.c \
				bonus/willcard_bonus.c \
				bonus/operators_bonus.c \

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

GNL_SRC		=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

GNL_OBJ		=	$(GNL_SRC:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(OBJ) $(GNL_OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a $(GNL_OBJ) -lreadline -o $(NAME)

$(NAME_BONUS):	$(OBJ_BONUS) $(GNL_OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ_BONUS) libft/libft.a $(GNL_OBJ) -lreadline -o $(NAME_BONUS)

clean:
	make clean -C libft
	$(RM) $(GNL_OBJ) $(OBJ) $(OBJ_BONUS)

fclean:			clean
	make fclean -C libft
	$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:	all bonus clean fclean re
