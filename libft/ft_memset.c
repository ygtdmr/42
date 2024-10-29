/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:01:10 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 21:18:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	flen;

	flen = len;
	if (c > 255)
		c = 0;
	while (len--)
		*((char *)b++) = c;
	return (b - flen);
}
