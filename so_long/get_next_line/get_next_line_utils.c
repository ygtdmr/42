/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:54:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/19 17:22:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	gnl_strfnl(char *s)
{
	while (s && *s)
	{
		if (*s++ == '\n')
			return (1);
	}
	return (0);
}

char	*gnl_bftostr(char *bf)
{
	char	*s;
	int		l;

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
		if (bf[i++] == '\n')
			break ;
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
	while (src && src[lsrc])
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
	if (dst)
		free(dst);
	if (src)
		free(src);
	return (tmp);
}
