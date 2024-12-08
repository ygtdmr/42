/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpflag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:01:24 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/06 20:47:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pflag	ft_getpflag(const char *f)
{
	t_pflag	flag;

	flag.zero = *f == '0';
	flag.plus = *f == '+';
	flag.minus = *f == '-';
	flag.space = *f == ' ';
	flag.hash = *f == '#';
	flag.width = 0;
	flag.precision = 0;
	while (ft_strchr("0+-# ", *f) != 0)
		f++;
	if (ft_isdigit(*f))
		flag.width = ft_atoi(f);
	while (ft_isdigit(*f))
		f++;
	if (*f == '.')
	{
		flag.precision = ft_atoi(++f);
		if (!flag.precision)
			flag.precision = -1;
	}
	return (flag);
}
