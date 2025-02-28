/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:36:24 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 20:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	nbr_i(t_stack *s, int n)
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

static int	nbr_ic(t_stack *sa, t_stack *sb, int na, int nb)
{
	int	ia;
	int	ib;
	int	it;

	ia = nbr_i(sa, na);
	ib = nbr_i(sb, nb);
	it = ia + ib;
	if (stack_size(sb) < 2)
		return (it);
	if (nbr_mv_side(sa, na) == nbr_mv_side(sb, nb))
	{
		if (ia > ib)
			it = (((ia + ib) - (ia - ib)) / 2) + (ia - ib);
		else
			it = (((ia + ib) - (ib - ia)) / 2) + (ib - ia);
	}
	return (it);
}

void	nbr_set(t_stack *sa, t_stack *sb, int *na, int *nb)
{
	t_stack	*tmp;
	int		itmp;
	int		it;

	it = -1;
	tmp = sa;
	while (tmp)
	{
		itmp = nbr_ic(sa, sb, tmp->nbr, nbr_prev(sb, &tmp->nbr));
		if (it == -1 || it > itmp)
		{
			it = itmp;
			*na = tmp->nbr;
			*nb = nbr_prev(sb, &tmp->nbr);
		}
		tmp = tmp->next;
	}
}
