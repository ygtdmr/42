/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:40:43 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 21:56:26 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*bs;
	char	ch;

	bs = (char *) s;
	ch = (char) c;
	while (n--)
	{
		if (*bs == ch)
			return (bs);
		bs++;
	}
	return (0);
}
