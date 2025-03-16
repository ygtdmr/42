/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:32:35 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 14:22:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;
	size_t	ldst;
	size_t	ldcat;

	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	if (dstsize && dstsize != (ldst + 1) && dstsize > ldst)
	{
		ldcat = dstsize - 1;
		if (ldcat > ldst)
			ldcat -= ldst;
		dst += ldst;
		while (*src && ldcat--)
			*dst++ = *src++;
		*dst = 0;
	}
	if (dstsize < ldst)
		return (dstsize + lsrc);
	else
		return (ldst + lsrc);
}
