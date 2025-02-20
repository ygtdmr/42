/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_mv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:12:57 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/21 02:05:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	mv_str_in(char *str, char *n)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!*n || (*str != *n))
			return (0);
		n++;
		str++;
	}
	return (1);
}

static void	mv_action(t_stack **sa, t_stack **sb, int na, int nb)
{
	char	*aa;
	char	*ab;

	aa = 0;
	ab = 0;
	if (!(*sa && *(*sa)->nbr == na) && nbr_mv_side(*sa, na))
		aa = "ra";
	else if (!(*sa && *(*sa)->nbr == na))
		aa = "rra";
	if (!(*sb && *(*sb)->nbr == nb) && nbr_mv_side(*sb, nb))
		ab = "rb";
	else if (!(*sb && *(*sb)->nbr == nb))
		ab = "rrb";
	if (mv_str_in(aa, "ra") && mv_str_in(ab, "rb"))
		do_action("rr", sa, sb);
	else if (mv_str_in(aa, "rra") && mv_str_in(ab, "rrb"))
		do_action("rrr", sa, sb);
	else
	{
		if (aa)
			do_action(aa, sa, 0);
		if (ab)
			do_action(ab, 0, sb);
	}
}

void	nbr_mv_b(t_stack **sa, t_stack **sb, int na, int nb)
{
	while (!(*sa && *(*sa)->nbr == na) || !(*sb && *(*sb)->nbr == nb))
		mv_action(sa, sb, na, nb);
}

static int	sa_sorted(t_stack *s)
{
	while (s->next)
	{
		if (*s->nbr > *s->next->nbr)
			return (0);
		s = s->next;
	}
	return (1);
}

void	nbr_mv_a(t_stack **sa, t_stack **sb)
{
	while (!sa_sorted(*sa))
	{
		if (*(*sa)->nbr > *(*sa)->next->nbr)
			do_action("sa", sa, 0);
		if (!sa_sorted(*sa))
			do_action("rra", sa, 0);
	}
	while (*sb)
	{
		while (nbr_next(*sa, (*sb)->nbr) != (*sa)->nbr)
			do_action("rra", sa, 0);
		do_action("pa", sa, sb);
	}
	while ((*sa)->nbr != nbr_next(*sa, 0))
	{
		if (nbr_mv_side(*sa, *nbr_next(*sa, 0)))
			do_action("ra", sa, 0);
		else
			do_action("rra", sa, 0);
	}
}
