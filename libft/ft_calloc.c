/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:01:05 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 16:14:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	max;

	max = SIZE_MAX;
	if ((count >= max && size > 0) || (size >= max && count > 0))
		return (0);
	max = INT_MIN;
	if ((count >= max && size > 0) || (size >= max && count > 0))
		return (0);
	max = INT_MAX;
	if ((count >= max && size > 0) || (size >= max && count > 0))
		return (0);
	p = malloc(count * size);
	if (p)
		ft_memset(p, 0, count * size);
	return (p);
}
