/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:13:26 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/02 06:38:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_lrealloc(char *dest, char *src, size_t length, int src_free)
{
	char	*out;
	size_t	l_out;
	size_t	i_out;
	size_t	i_src;

	i_out = 0;
	i_src = 0;
	if (dest)
		l_out = ft_strlen(dest) + length;
	else
		l_out = length;
	out = ft_calloc(l_out + 1, sizeof(char));
	while (dest && dest[i_out])
	{
		out[i_out] = dest[i_out];
		i_out++;
	}
	while (src && *src && i_src < length)
		out[i_out++] = src[i_src++];
	if (dest)
		free(dest);
	if (src && src_free)
		free(src);
	return (out);
}

char	*str_realloc(char *dest, char *src, int src_free)
{
	if (!src)
		return (dest);
	return (str_lrealloc(dest, src, ft_strlen(src), src_free));
}

int	str_match(char *dest, char *src)
{
	char	*s;

	if (!(dest && src))
		return (0);
	s = ft_strnstr(dest, src, ft_strlen(dest));
	return (s && (ft_strlen(dest) == ft_strlen(src)));
}

void	str_lclean(char **dest, size_t length)
{
	char	*s;

	if (!(length && *dest))
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

int	str_mc(char **dest, char *needle)
{
	size_t	lneedle;

	if (!*dest)
		return (0);
	lneedle = ft_strlen(needle);
	if (ft_strnstr(*dest, needle, lneedle))
	{
		str_lclean(dest, lneedle);
		return (1);
	}
	return (0);
}
