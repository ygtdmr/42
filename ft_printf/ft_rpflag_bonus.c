/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rpflag_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:13:01 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/08 10:34:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*r_diux(const char *f, t_pflag flag, char *s)
{
	char	fc;
	int		ls;
	int		isn;

	if (flag.precision == -1 && *s == '0')
	{
		free(s);
		return (ft_strdup(""));
	}
	if (flag.plus && *s != '-')
		fc = '+';
	else if (flag.space && *s != '-')
		fc = ' ';
	if (*f == '+' || *f == ' ')
		s++;
	isn = (*s == '-');
	ls = ft_strlen(s) - isn;
	if (flag.precision > ls)
	{
		flag.precision = (flag.precision - ls);
		while (flag.precision-- > 0)
			s = ft_strjcf('0', s, 0);
	}
	return (ft_strjcf(fc, s, 0));
}

static char	*r_s(t_pflag flag, char *s)
{
	char	*stmp;

	stmp = 0;
	if (flag.precision == -1)
		stmp = ft_strdup("");
	else if (flag.precision)
		stmp = ft_substr(s, 0, flag.precision);
	if (stmp)
	{
		free(s);
		return (stmp);
	}
	return (s);
}

static char	*r_width(t_pflag flag, char *s)
{
	int	ls;

	ls = ft_strlen(s);
	flag.width = flag.width - ls;
	while (flag.width > 0 && flag.width--)
	{
		if (flag.minus)
			s = ft_strjcf(' ', s, 1);
		else if (!flag.precision && flag.zero)
			s = ft_strjcf('0', s, 0);
		else
			s = ft_strjcf(' ', s, 0);
	}
	return (s);
}

char	*ft_rpflag(const char *f, char *s)
{
	t_pflag	flag;
	char	type;

	type = *(f + (ft_ispformat(f) - 1));
	flag = ft_getpflag(f + 1);
	if ((type == 'x' || type == 'X') && flag.hash && *s != '0')
	{
		s = ft_strjcf(type, s, 0);
		s = ft_strjcf('0', s, 0);
	}
	else if (ft_strchr("diuxX", type) != 0)
		s = r_diux(f, flag, s);
	else if (type == 's')
		s = r_s(flag, s);
	s = r_width(flag, s);
	if ((flag.zero || flag.precision) && ft_strchr(s, '-') != 0)
	{
		*ft_strchr(s, '-') = '0';
		*ft_strchr(s, '0') = '-';
	}
	return (s);
}
