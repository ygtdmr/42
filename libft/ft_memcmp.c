/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:10:00 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/04 17:21:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bs1;
	unsigned char	*bs2;

	bs1 = (unsigned char *) s1;
	bs2 = (unsigned char *) s2;
	while (n--)
	{
		if (*bs1 != *bs2)
			return (*bs1 - *bs2);
		bs1++;
		bs2++;
	}
	return (0);
}
