/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:38:05 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/17 19:43:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_clear(t_stack **s, void (*del)(void*))
{
	if (!s || !*s)
		return ;
	if ((*s)->nbr != 0)
		del((*s)->nbr);
	if ((*s)->next)
		stack_clear(&(*s)->next, del);
	free(*s);
	*s = 0;
}
