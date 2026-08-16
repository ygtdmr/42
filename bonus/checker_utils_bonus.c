/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:58 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 22:16:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>

static int	valid_action(char *ac)
{
	int	v;

	v = 0;
	if (ft_strlen(ac) == 2)
	{
		v = ft_strnstr(ac, "sa", 2) != 0;
		v = (v || ft_strnstr(ac, "sb", 2) != 0);
		v = (v || ft_strnstr(ac, "ss", 2) != 0);
		v = (v || ft_strnstr(ac, "pa", 2) != 0);
		v = (v || ft_strnstr(ac, "pb", 2) != 0);
		v = (v || ft_strnstr(ac, "ra", 2) != 0);
		v = (v || ft_strnstr(ac, "rb", 2) != 0);
		v = (v || ft_strnstr(ac, "rr", 2) != 0);
	}
	else if (ft_strlen(ac) == 3)
	{
		v = ft_strnstr(ac, "rra", 3) != 0;
		v = (v || ft_strnstr(ac, "rrb", 3) != 0);
		v = (v || ft_strnstr(ac, "rrr", 3) != 0);
	}
	return (v);
}

char	**valid_actions(char **splt)
{
	int	i;

	i = 0;
	while (splt[i])
	{
		if (!valid_action(splt[i]))
			return (0);
		i++;
	}
	return (splt);
}

char	*str_realloc(char *dst, char *src, size_t lsrc)
{
	char	*s;
	size_t	ls;
	size_t	ldst;

	ldst = 0;
	if (dst)
		ldst = ft_strlen(dst);
	ls = ldst + lsrc;
	s = (char *) ft_calloc((ls + 1), sizeof(char));
	if (!s)
		return (0);
	if (dst)
		ft_strlcpy(s, dst, ldst + 1);
	ft_strlcpy(s + ldst, src, ls + 1);
	if (dst)
		free(dst);
	return (s);
}

void	clear_actions(char **acl)
{
	int	i;

	if (!acl)
		return ;
	i = 0;
	if (acl && !acl[i])
		free(acl[i]);
	while (acl[i])
		free(acl[i++]);
	free(acl);
}

char	*get_actions(void)
{
	char	*acs;
	char	bf[5];
	int		bfl;

	acs = 0;
	while (1)
	{
		bfl = read(0, bf, 4);
		if (bfl <= 0)
			break ;
		bf[bfl] = 0;
		acs = str_realloc(acs, bf, bfl);
	}
	return (acs);
}
