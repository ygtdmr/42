/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:38:39 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/05 19:38:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ispformat(const char *s)
{
	int		l;
	int		isf;

	if (*s != '%')
		return (0);
	l = 1 + ft_ispflag(s);
	s += l;
	isf = ft_strchr("cspdiuxX%", *s) != 0;
	if (isf)
		return (l + isf);
	else
		return (0);
}
