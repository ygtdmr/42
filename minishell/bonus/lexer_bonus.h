/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/09 14:05:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_BONUS_H
# define LEXER_BONUS_H

# include "minishell_bonus.h"

void	new_tok(t_token	**head, char *value, t_toktype type);
void	clear_tok(t_token **head);
void	add_tok(t_token **head, t_token *new);
void	lexer(t_shell *sh, char **line);

#endif
