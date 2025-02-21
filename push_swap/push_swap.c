/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:58 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/21 18:19:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_error(t_stack *s)
{
	write(2, "Error\n", 6);
	stack_clear(&s, free);
	return (1);
}

static void	stack_sml_sort(t_stack **sa)
{
	t_stack	*sb;

	sb = 0;
	while (stack_size(*sa) >= 3)
	{
		while ((*sa)->nbr != nbr_next(*sa, 0))
		{
			if (nbr_mv_side(*sa, *nbr_next(*sa, 0)))
				do_action("ra", sa, 0);
			else
				do_action("rra", sa, 0);
		}
		do_action("pb", sa, &sb);
	}
	if (*(*sa)->nbr > *(*sa)->next->nbr)
		do_action("sa", sa, 0);
	while (sb)
		do_action("pa", sa, &sb);
	stack_clear(&sb, free);
}

static void	stack_big_sort(t_stack **sa)
{
	t_stack	*sb;
	int		*na;
	int		*nb;

	sb = 0;
	while (stack_size(*sa) > 3)
	{
		nbr_set(*sa, sb, &na, &nb);
		if (stack_size(sb) >= 2)
			nbr_mv_b(sa, &sb, *na, *nb);
		do_action("pb", sa, &sb);
	}
	nbr_mv_a(sa, &sb);
	stack_clear(&sb, free);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	if (!args_to_stack(argc - 1, argv + 1, &stack))
		return (stack_error(stack));
	if (!stack_sorted(stack))
	{
		if (stack_size(stack) > 5)
			stack_big_sort(&stack);
		else
			stack_sml_sort(&stack);
	}
	stack_clear(&stack, free);
	return (0);
}
