/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:16:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/09 16:09:48 by yidemir          ###   ########.fr       */
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

static void	add_tok(t_token **lst, char *value, t_toktype type)
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
	lstadd_back_tok(lst, new);
}

static int	mch_tok(char **line, char *needle)
{
	size_t	lneedle;

	lneedle = ft_strlen(needle);
	if (ft_strnstr(*line, needle, lneedle))
	{
		*line += lneedle;
		return (1);
	}
	return (0);
}

void	lstclear_tok(t_token **lst)
{
	t_token	*ilst;

	if (!lst)
		return ;
	ilst = *lst;
	if (!ilst)
		return ;
	if (ilst->value != 0)
		free(ilst->value);
	if (ilst->next)
		lstclear_tok(&ilst->next);
	free(ilst);
	*lst = 0;
}

t_token	*lexer(char *line, t_shell *shell)
{
	t_token	*head;

	head = 0;
	while (*line)
	{
		if (mch_tok(&line, " ") || mch_tok(&line, "\t") || mch_tok(&line, "\n"))
			continue ;
		if (mch_tok(&line, "|"))
			add_tok(&head, ft_strdup("|"), T_PIPE);
		else if (mch_tok(&line, ">>"))
			add_tok(&head, ft_strdup(">>"), T_REDIR_APND);
		else if (mch_tok(&line, "<<"))
			add_tok(&head, ft_strdup("<<"), T_HEREDOC);
		else if (mch_tok(&line, "<"))
			add_tok(&head, ft_strdup("<"), T_REDIR_IN);
		else if (mch_tok(&line, ">"))
			add_tok(&head, ft_strdup(">"), T_REDIR_OUT);
		else
			add_tok(&head, expand(grab_word(&line), shell), T_WORD);
	}
	return (head);
}
