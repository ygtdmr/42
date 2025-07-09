/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:05:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/09 14:05:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_bonus.h"

void	add_tok(t_token **head, t_token *new)
{
	t_token	*nlst;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	nlst = *head;
	while (nlst->next)
		nlst = nlst->next;
	nlst->next = new;
}

void	new_tok(t_token	**head, char *value, t_toktype type)
{
	t_token	*new;

	if (!value)
		return ;
	new = malloc(sizeof(t_token));
	if (!new)
		return ;
	new->value = value;
	new->type = type;
	new->next = 0;
	add_tok(head, new);
}

void	clear_tok(t_token **head)
{
	t_token	*token;

	if (!head)
		return ;
	token = *head;
	if (!token)
		return ;
	if (token->value)
		free(token->value);
	if (token->next)
		clear_tok(&token->next);
	free(token);
	*head = 0;
}
