/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_mv_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:06:46 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/21 14:36:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nbr_mv_side(t_stack *stack, int nbr)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (*tmp->nbr == nbr)
			break ;
		tmp = tmp->next;
	}
	return (stack_size(tmp) > (stack_size(stack) / 2));
}
