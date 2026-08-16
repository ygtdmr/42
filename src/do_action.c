/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:24:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 20:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_action(char *a, t_stack **sa, t_stack **sb)
{
	if (stack_action(a, sa, sb))
	{
		write(1, a, ft_strlen(a));
		write(1, "\n", 1);
	}
}
