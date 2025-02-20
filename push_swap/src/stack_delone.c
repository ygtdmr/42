/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:30:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/17 19:51:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_delone(t_stack *s, void (*del)(void*))
{
	if (!s)
		return ;
	if (s->nbr != 0)
		del(s->nbr);
	free(s);
}
