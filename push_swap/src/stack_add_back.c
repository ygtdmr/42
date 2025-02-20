/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:06:07 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/17 21:20:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_add_back(t_stack **s, t_stack *n)
{
	t_stack	*tmp;

	if (!n)
		return ;
	if (!*s)
	{
		*s = n;
		return ;
	}
	tmp = *s;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
}
