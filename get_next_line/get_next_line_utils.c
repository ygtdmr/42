/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:54:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/17 16:30:02 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*gnl_readline(char *s, char *bf, int bfi)
{
	char	*ns;
	int		l;
	
	l = bfi;
	ns = (char *) malloc((l + 1) * sizeof(char));
	if (!ns && s)
		free(s);
	if (!ns)
		return (0);
	ns[l] = 0;
	while (l--)
		ns[l] = bf[l];
	ft_memmove(bf, bf + bfi, bfi);
	ft_memset(bf + ((bf + bfi) - bf), 0, bfi);
	return (gnl_strmerge(s, ns));
}

int	gnl_readbf(int fd, char *bf, int *bfi, int bfl)
{
	if (bf[*bfi])
		return (bfl);
	ft_memset(bf, 0, bfl);
	*bfi = 0;
	return (read(fd, bf, BUFFER_SIZE));
}

char	*gnl_strmerge(char *dst, char *src)
{
	char	*tmp;
	int		ldst;
	int		lsrc;

	ldst = 0;
	lsrc = 0;
	while(dst && dst[ldst])
		ldst++;
	if (!ldst)
		return (src);
	while (src[lsrc])
		lsrc++;
	tmp = (char *) malloc((ldst + lsrc + 1) * sizeof(char));
	if (!tmp)
	{
		free(src);
		return (0);
	}
	while (lsrc--)
		tmp[ldst + lsrc] = src[lsrc];
	while (ldst--)
		tmp[ldst] = dst[ldst];
	free(src);
	free(dst);
	return (tmp);
}

void	*ft_memset(void *b, int c, size_t len)
{
	void	*fb;

	fb = b;
	while (len--)
		*((char *)b++) = c;
	return (fb);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;

	cdst = (char *) dst;
	csrc = (const char *) src;
	if (!src && !dst)
		return (0);
	if (cdst < csrc)
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	else
	{
		while (len--)
			cdst[len] = csrc[len];
	}
	return (dst);
}
