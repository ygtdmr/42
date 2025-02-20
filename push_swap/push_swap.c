/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:58 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/21 02:10:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_sort(t_stack **sa)
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
	stack = args_to_stack(argc - 1, argv + 1);
	if (stack_size(stack) == 1)
		return (0);
	stack_sort(&stack);
	stack_clear(&stack, free);
	return (0);
}
