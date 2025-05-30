/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/30 21:29:04 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

int		mch_str(char **dest, char *needle);
void	str_lclean(char **dest, size_t length);
void	new_tok(t_token	**head, char *value, t_toktype type);
void	clear_tok(t_token **head);
void	add_tok(t_token **head, t_token *new);
void	lexer(t_shell *sh, char **line);

#endif
