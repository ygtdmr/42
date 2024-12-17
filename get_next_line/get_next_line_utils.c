/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:54:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/17 22:09:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	gnl_strlc(char *s, char c)
{
	while (s && *s)
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}

char	*gnl_bftostr(char *bf)
{
	char	*s;
	int		l;

	if (!bf)
		return (0);
	l = 0;
	while (bf[l])
	{
		if (bf[l++] == '\n')
			break ;
	}
	s = (char *) malloc((l + 1) * sizeof(char));
	if (!s)
		return (0);
	s[l] = 0;
	while (l--)
		s[l] = bf[l];
	return (s);
}

void	gnl_bfmv(char *bf)
{
	int	i;
	int	ic;

	i = 0;
	ic = 0;
	while (bf[i])
	{
		if (bf[i] == '\n')
		{
			bf[i++] = 0;
			break ;
		}
		else
			bf[i] = 0;
		i++;
	}
	while (bf[i])
		bf[ic++] = bf[i++];
	while (bf[ic])
		bf[ic++] = 0;
}

char	*gnl_strmerge(char *dst, char *src)
{
	char	*tmp;
	int		ldst;
	int		lsrc;

	ldst = 0;
	lsrc = 0;
	while (dst && dst[ldst])
		ldst++;
	if (!ldst)
		return (src);
	while (src[lsrc])
		lsrc++;
	tmp = (char *) malloc((ldst + lsrc + 1) * sizeof(char));
	if (tmp)
	{
		tmp[ldst + lsrc] = 0;
		while (lsrc--)
			tmp[ldst + lsrc] = src[lsrc];
		while (ldst--)
			tmp[ldst] = dst[ldst];
	}
	free(src);
	free(dst);
	return (tmp);
}
