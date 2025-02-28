/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_prev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:55:28 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 20:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nbr_prev(t_stack *s, int *nbr)
{
	t_stack	*tmp_s;
	int		tmp;

	tmp = 0;
	tmp_s = s;
	if (!s || !nbr)
		return (0);
	while (tmp_s)
	{
		if (tmp_s->nbr < *nbr && (tmp == 0 || tmp_s->nbr > tmp))
			tmp = tmp_s->nbr;
		tmp_s = tmp_s->next;
	}
	if (!tmp)
		return (nbr_max(s));
	return (tmp);
}
