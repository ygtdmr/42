/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:38:02 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 20:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (dstsize)
	{
		while (*src && ((dstsize--) - 1))
			*dst++ = *src++;
		*dst = 0;
	}
	return (lsrc);
}
