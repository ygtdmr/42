/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:50:34 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 20:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ac_push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!*from)
		return (0);
	stack_add_front(to, stack_new((*from)->nbr));
	tmp = (*from)->next;
	stack_delone((*from));
	*(from) = tmp;
	return (1);
}

static int	ac_swap(t_stack *s)
{
	int	tmp;

	if (stack_size(s) <= 1)
		return (0);
	tmp = s->nbr;
	s->nbr = s->next->nbr;
	s->next->nbr = tmp;
	return (1);
}

static int	ac_rotate(t_stack *s)
{
	int	tmp;

	if (stack_size(s) <= 1)
		return (0);
	tmp = s->nbr;
	while (s->next)
	{
		s->nbr = s->next->nbr;
		s = s->next;
	}
	s->nbr = tmp;
	return (1);
}

static int	ac_reverse_rotate(t_stack *s)
{
	int	tmp_c;
	int	tmp_n;

	if (stack_size(s) <= 1)
		return (0);
	tmp_c = s->nbr;
	s->nbr = stack_last(s)->nbr;
	while (s->next)
	{
		tmp_n = s->next->nbr;
		s->next->nbr = tmp_c;
		tmp_c = tmp_n;
		s = s->next;
	}
	return (1);
}

int	stack_action(char *a, t_stack **sa, t_stack **sb)
{
	if (ft_strnstr(a, "sa", 2))
		return (ac_swap(*sa));
	if (ft_strnstr(a, "sb", 2))
		return (ac_swap(*sb));
	if (ft_strnstr(a, "ss", 2))
		return (ac_swap(*sa), ac_swap(*sb));
	if (ft_strnstr(a, "pa", 2))
		return (ac_push(sb, sa));
	if (ft_strnstr(a, "pb", 2))
		return (ac_push(sa, sb));
	if (ft_strnstr(a, "rra", 3))
		return (ac_reverse_rotate(*sa));
	if (ft_strnstr(a, "rrb", 3))
		return (ac_reverse_rotate(*sb));
	if (ft_strnstr(a, "rrr", 3))
		return (ac_reverse_rotate(*sa), ac_reverse_rotate(*sb));
	if (ft_strnstr(a, "ra", 2))
		return (ac_rotate(*sa));
	if (ft_strnstr(a, "rb", 2))
		return (ac_rotate(*sb));
	if (ft_strnstr(a, "rr", 2))
		return (ac_rotate(*sa), ac_rotate(*sb));
	write(2, "Error\n", 6);
	exit(1);
}
