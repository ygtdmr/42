/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:05:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/28 12:54:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	str_lclean(char **dest, size_t length)
{
	char	*s;

	if (!length)
		return ;
	if (!(*dest)[length])
	{
		free(*dest);
		*dest = 0;
		return ;
	}
	s = ft_strdup((*dest) + length);
	free(*dest);
	*dest = s;
}

int	mch_str(char **dest, char *needle)
{
	size_t	lneedle;

	lneedle = ft_strlen(needle);
	if (ft_strnstr(*dest, needle, lneedle))
	{
		str_lclean(dest, lneedle);
		return (1);
	}
	return (0);
}

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
	new = malloc(sizeof(*new));
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
