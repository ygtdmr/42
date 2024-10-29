/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:14:39 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/29 10:36:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlent(const char *s, char const *set)
{
	char const	*fset;
	int			l;

	l = 0;
	fset = set;
	while (*s++ && *s != *set++)
	{
		l++;
		set = fset;
	}
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*fset;
	char		*fcs;
	char		*cs;
	int			t;

	if (!s1 || !set)
		return (0);
	cs = ft_calloc((ft_strlent(s1, set) + 1), sizeof(char));
	if (!cs)
		return (0);
	fset = set;
	fcs = cs;
	while (*s1++)
	{
		t = 0;
		set = fset;
		while (*set)
		{
			if (*(s1 - 1) == *set++)
				t = 1;
		}
		if (!t)
			*cs++ = *(s1 - 1);
	}
	return (fcs);
}
