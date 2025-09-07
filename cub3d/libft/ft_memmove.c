/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:44:50 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/04 17:22:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
