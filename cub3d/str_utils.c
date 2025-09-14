/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:43:43 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/09 12:46:28 by yidemir          ###   ########.fr       */
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

int	str_ms(char **dest, char *src)
{
	size_t	i_dest;
	size_t	i_src;

	i_dest = 0;
	i_src = 0;
	while ((*dest && src) && (*dest)[i_dest])
	{
		if (i_src && !src[i_src])
		{
			(*dest) += i_dest;
			return (1);
		}
		if ((*dest)[i_dest] == src[i_src])
			i_src++;
		else
			return (0);
		i_dest++;
	}
	return (0);
}

int	str_ts(char **dest, char *set)
{
	int		found;
	size_t	i_dest;
	size_t	i_set;

	i_dest = 0;
	while ((*dest)[i_dest])
	{
		i_set = 0;
		found = 0;
		while (set[i_set])
		{
			if (set[i_set] == (*dest)[i_dest])
			{
				found = 1;
				break ;
			}
			i_set++;
		}
		if (!found)
			break ;
		i_dest++;
	}
	*dest += i_dest;
	return (i_dest > 0);
}
