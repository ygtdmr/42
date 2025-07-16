/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:30:10 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/16 14:12:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_philo *philos;
	t_rules *r;
	int		all_full;
	int		i;

	philos = (t_philo *)arg;
	r = philos[0].r;
	while (!r->stop)
	{
		i = -1;
		all_full = 1;
		while (++i < r->n_philo)
		{
			if (now_ms() - philos[i].last_meal > r->t_die)
			{
				print_action(r, philos[i].id, "died");
				r->stop = 1;
			}
			if (r->must_eat == -1 || philos[i].eaten < r->must_eat)
				all_full = 0;
		}
		if (all_full)
			r->stop = 1;
		usleep(1000);
	}
	return (0);
}
