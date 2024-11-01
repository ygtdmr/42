/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:10:00 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 12:39:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bs1;
	unsigned char	*bs2;

	bs1 = (unsigned char *) s1;
	bs2 = (unsigned char *) s2;
	while (n--)
	{
		if (*bs1 > *bs2)
			return (1);
		if (*bs1++ < *bs2++)
			return (-1);
	}
	return (0);
}
