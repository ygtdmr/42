/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:16:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/04 16:02:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	lstadd_back_tok(t_token **lst, t_token *new)
{
	t_token	*nlst;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	nlst = *lst;
	while (nlst->next)
		nlst = nlst->next;
	nlst->next = new;
}

static void  add_tok(t_token **lst, char *value, t_toktype type)
{
	t_token	*new;

	new = malloc(sizeof(*new));
	if (!new)
	{
		write(2, "malloc error\n", 13);
		exit(1);
	}
	new->value = value;
	new->type = type;
	new->next = 0;
	lstadd_back_tok(lst, new);
}

static int	match_tok(char **line, char *needle)
{
	int	lneedle;

	lneedle = ft_strlen(needle);
	if (ft_strnstr(*line, needle, lneedle))
	{
		*line += lneedle;
		return (1);
	}
	return (0);
}

t_token *lexer(char *line)
{
	t_token *head;

	head = 0;
	while (*line)
	{
		if (*line == ' ')
		{
			line++;
			continue ;
		}
		if (match_tok(&line, "|"))
			add_tok(&head, ft_strdup("|"), T_PIPE);
		else if (match_tok(&line, "<"))
			add_tok(&head, ft_strdup("<"), T_REDIR_IN);
		else if (match_tok(&line, ">"))
			add_tok(&head, ft_strdup(">"), T_REDIR_OUT);
		else if (match_tok(&line, ">>"))
			add_tok(&head, ft_strdup(">>"), T_REDIR_APND);
		else if (match_tok(&line, "<<"))
			add_tok(&head, ft_strdup("<<"), T_HEREDOC);
		else
			add_tok(&head, grab_word(&line), T_WORD);
	}
	return head;
}
