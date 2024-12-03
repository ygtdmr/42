/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:34:56 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/03 18:19:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countd(int n)
{
	int	d;

	d = 1;
	while (n >= 10)
	{
		d++;
		n /= 10;
	}
	return (d);
}

static int	putfree(char *s)
{
	int		l;

	l = ft_putstr(s);
	free(s);
	return (l);
}

int	ft_putint(int n)
{
	int		ls;
	int		isn;
	char	*s;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	isn = n < 0;
	if (isn)
		n = -n;
	ls = countd(n) + isn;
	s = (char *) malloc((ls + 1) * sizeof(char));
	if (!s)
		return (-1);
	s[ls] = 0;
	while (ls--)
	{
		if (ls == 0 && isn)
			s[0] = 45;
		else
			s[ls] = 48 + (n % 10);
		n /= 10;
	}
	return (putfree(s));
}
