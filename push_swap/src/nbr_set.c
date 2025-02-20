/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:36:24 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/21 02:01:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	nbr_i(t_stack *s, int *n)
{
	int	i;
	int	lc;

	if (!s || !n)
		return (0);
	i = 0;
	lc = stack_size(s) / 2;
	while (s)
	{
		if (s->nbr == n)
			break ;
		i++;
		s = s->next;
	}
	if (i > lc)
		i = (lc - (i - lc)) + 1;
	return (i);
}

static int	nbr_ic(t_stack *s1, t_stack *s2, int *n1, int *n2)
{
	int	i1;
	int	i2;
	int	it;

	i1 = nbr_i(s1, n1);
	i2 = nbr_i(s2, n2);
	it = i1 + i2;
	if (stack_size(s2) < 2)
		return (it);
	if (nbr_mv_side(s1, *n1) == nbr_mv_side(s2, *n2))
	{
		if (i1 > i2)
			it = (((i1 + i2) - (i1 - i2)) / 2) + (i1 - i2);
		else
			it = (((i1 + i2) - (i2 - i1)) / 2) + (i2 - i1);
	}
	return (it);
}

static int	nbr_sc(t_stack *s1, t_stack *s2, int **n1, int **n2)
{
	t_stack	*tmp;
	int		itmp;
	int		it;

	it = -1;
	tmp = s1;
	while (tmp)
	{
		itmp = nbr_ic(s1, s2, tmp->nbr, nbr_prev(s2, tmp->nbr));
		if (it == -1 || it > itmp)
		{
			it = itmp;
			*n1 = tmp->nbr;
			*n2 = nbr_prev(s2, tmp->nbr);
		}
		tmp = tmp->next;
	}
	return (it);
}

void	nbr_set(t_stack *sa, t_stack *sb, int **na, int **nb)
{
	int	sca;
	int	scb;

	if (!sb && !sa)
		return ;
	sca = nbr_sc(sa, sb, na, nb);
	scb = nbr_sc(sb, sa, nb, na);
	if ((sca <= scb) || scb != -1)
		nbr_sc(sa, sb, na, nb);
}
