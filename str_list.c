/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:35:00 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/15 18:43:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_sl(char ***sl, char *val)
{
	char	**tmp;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (*sl && (*sl)[len])
		len++;
	tmp = ft_calloc((len + 2), sizeof(char *));
	if (*sl)
	{
		while (i < len)
		{
			tmp[i] = (*sl)[i];
			i++;
		}
		free(*sl);
	}
	tmp[i] = val;
	*sl = tmp;
}

char	**dup_sl(char **sl)
{
	size_t	len;
	size_t	i;
	char	**dup;

	if (!sl)
		return (0);
	len = 0;
	i = 0;
	while (sl[len])
		len++;
	dup = ft_calloc(len + 1, sizeof(char *));
	while (i < len)
	{
		dup[i] = ft_strdup(sl[i]);
		i++;
	}
	return (dup);
}

void	clear_sl(char **sl)
{
	size_t	i;

	if (!sl)
		return ;
	i = 0;
	while (sl[i])
		free(sl[i++]);
	free(sl);
}
