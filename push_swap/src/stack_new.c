/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:16:20 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 20:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_new(int *nbr)
{
	t_stack	*lst;

	lst = (t_stack *) malloc(sizeof(t_stack));
	if (!lst)
		return (0);
	lst->nbr = nbr;
	lst->next = 0;
	return (lst);
}
