/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:58 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/03 13:52:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_error(t_stack **sa, t_stack **sb)
{
	write(2, "Error\n", 6);
	stack_clear(sa);
	stack_clear(sb);
	return (1);
}

static void	stack_sml_sort(t_stack **sa, t_stack **sb)
{
	if (stack_size(*sa) == 5)
	{
		while (stack_size(*sb) < 2)
		{
			while ((*sa)->nbr != nbr_next(*sa, 0))
			{
				if (nbr_mv_side(*sa, nbr_next(*sa, 0)))
					do_action("ra", sa, 0);
				else
					do_action("rra", sa, 0);
			}
			do_action("pb", sa, sb);
		}
	}
	while (!stack_sorted(*sa))
	{
		if ((*sa)->nbr != nbr_max(*sa) && ((*sa)->nbr > (*sa)->next->nbr))
			do_action("sa", sa, 0);
		if (!stack_sorted(*sa))
			do_action("ra", sa, 0);
	}
	while (*sb)
		do_action("pa", sa, sb);
}

static void	stack_big_sort(t_stack **sa, t_stack **sb)
{
	nbr_mv_b(sa, sb);
	nbr_mv_a(sa, sb);
}

int	main(int argc, char **argv)
{
	t_stack	*sa;
	t_stack	*sb;

	if (argc < 2)
		return (0);
	sb = 0;
	if (!args_to_stack(--argc, ++argv, &sa))
		return (stack_error(&sa, &sb));
	if (!stack_sorted(sa))
	{
		if (stack_size(sa) > 5)
			stack_big_sort(&sa, &sb);
		else
			stack_sml_sort(&sa, &sb);
	}
	stack_clear(&sa);
	stack_clear(&sb);
	return (0);
}
