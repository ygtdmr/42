/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:50:26 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 21:16:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ilen(int i)
{
	int	l;

	l = 0;
	if (i < 0)
		i *= -1;
	while (i >= 10)
	{
		i /= 10;
		l++;
	}
	return (l + 1);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		ln;
	int		isn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ln = ilen(n);
	isn = n < 0;
	s = ft_calloc(ln + isn + 1, sizeof(char));
	if (!s)
		return (0);
	if (isn)
	{
		n *= -1;
		*s = 45;
	}
	while (ln)
	{
		*(s + (isn + --ln)) = 48 + (n % 10);
		n /= 10;
	}
	return (s);
}
