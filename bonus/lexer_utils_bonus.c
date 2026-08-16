/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:05:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/11 08:17:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
	new->prev = nlst;
	nlst->next = new;
}

void	new_tok(t_token	**head, char *value, t_toktype type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return ;
	ft_bzero(new, sizeof(t_token));
	new->value = value;
	new->type = type;
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
	if (token->raw_word)
		free(token->raw_word);
	if (token->i_wc)
		free(token->i_wc);
	if (token->next)
		clear_tok(&token->next);
	free(token);
	*head = 0;
}

t_token	*lst_tok(t_token *head)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

int	lst_tok_is(t_token *head, t_toktype type)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head->type == type);
}
