/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:09:27 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/24 14:22:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_printf(const char *f, ...)
{
	va_list	args;
	size_t	l;
	int		i;
	int		ispf;

	l = 0;
	i = 0;
	va_start(args, f);
	while (f[i])
	{
		ispf = ft_ispf(&f[i]);
		if (ispf)
		{
			write(1, f, i);
			l += ft_putf(&f[i], args);
			f += i + ispf;
			i = 0;
		}
		if (!f[++i])
			l += ft_putstr(f);
	}
	va_end(args);
	return (l);
}
