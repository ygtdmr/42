/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:18:09 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/04 23:46:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	baselen(int lb, size_t v)
{
	int	l;

	l = 0;
	while (v > 0)
	{
		v /= lb;
		l++;
	}
	return (l);
}

char	*ft_base(char *b, size_t v)
{
	char	*s;
	size_t	lb;
	int		ls;

	if (!v)
		return (ft_strdup("0"));
	lb = ft_strlen(b);
	ls = baselen(lb, v);
	s = (char *) ft_calloc(ls + 1, sizeof(char));
	if (!s)
		return (0);
	while (ls--)
	{
		s[ls] = b[v % lb];
		if (v >= lb)
			v /= lb;
	}
	return (s);
}
