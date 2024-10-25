/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:40:43 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/24 18:45:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*bs;

	bs = (char *) s;
	if (c > 255)
		c -= 256;
	while (n--)
	{
		if (*bs == c)
			return (bs);
		bs++;
	}
	return (0);
}
