/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:55:28 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 20:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*nbr_next(t_stack *s, int *nbr)
{
	int		*next;
	int		*tmp;

	if (!s)
		return (0);
	if (nbr && *nbr >= *nbr_max(s))
		return (nbr_next(s, 0));
	next = s->nbr;
	while (s->next)
	{
		tmp = s->next->nbr;
		if (nbr)
		{
			if ((*nbr >= *next || *next > *tmp) && *tmp > *nbr)
				next = tmp;
		}
		else if (*next > *tmp)
			next = tmp;
		s = s->next;
	}
	return (next);
}
