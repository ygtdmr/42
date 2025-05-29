/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:08:51 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/29 15:05:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	argv_push(char ***dest, char *src)
{
	char	**argv;
	int		i;

	i = 0;
	while ((*dest)[i])
		i++;
	argv = ft_calloc(++i, sizeof(char *));
	i = 0;
	while ((*dest)[i])
	{
		argv[i] = (*dest)[i];
		i++;
	}
	argv[i] = src;
	free(*dest);
	*dest = argv;
}

t_cmd	*new_cmd(t_cmd	**head)
{
	t_cmd	*last_head;
	t_cmd	*new;

	if (!head)
		return (0);
	last_head = 0;
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (0);
	new->next = 0;
	if (*head)
	{
		last_head = *head;
		while (last_head->next)
			last_head = last_head->next;
		last_head->next = new;
	}
	else
		*head = new;
	return (new);
}
