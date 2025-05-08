/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/08 21:14:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum e_toktype
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APND,
	T_HEREDOC
}	t_toktype;

typedef struct s_token
{
	char			*value;
	t_toktype		type;
	struct s_token	*next;
}	t_token;

char	*sanitize_escape(char *line);
char	*grab_word(char **line);
void	lstclear_tok(t_token **lst);
int		is_metachar(char *s);
int		is_varchar(char c, size_t index);
char	*str_lrealloc(char *dest, char *src, size_t length);
char	*expand(char *raw, t_shell *sh);
t_token	*lexer(char *line, t_shell *sh);

#endif
