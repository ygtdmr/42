/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:33:25 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/28 12:13:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

size_t	char_len(char c, char *str)
{
	size_t	length;

	length = 0;
	while (str && *str)
		length += (*str++ == c);
	return (length);
}

int	is_varchar(char c, size_t index)
{
	if (index == 0)
		return (ft_isalpha(c) || c == '_');
	else
		return (ft_isalnum(c) || c == '_');
}

char	*str_lrealloc(char *dest, char *src, size_t length)
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
	return (out);
}
