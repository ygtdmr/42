/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:01:05 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 12:47:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checklimit(size_t max, size_t count, size_t size)
{
	return ((count >= max && size > 0) || (size >= max && count > 0));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	int		ismax;

	ismax = checklimit(18446744073709551615UL, count, size);
	ismax = ismax || checklimit(-2147483648, count, size);
	ismax = ismax || checklimit(2147483647, count, size);
	if (ismax)
		return (0);
	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}
