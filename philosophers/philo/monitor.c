/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/26 11:10:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	watch(t_rules *rules, t_philo *philos)
{
	int	all_full;
	int	i;

	while (!stop(rules, -1))
	{
		i = -1;
		all_full = 1;
		while (++i < rules->n_philo)
		{
			if ((now_ms() - last_meal(philos + i, -1)) > rules->t_die)
			{
				print_action(rules, philos[i].id, "died");
				stop(rules, 1);
			}
			if (rules->must_eat == -1 || (eat(philos + i, 0) < rules->must_eat))
				all_full = 0;
		}
		if (all_full)
			stop(rules, 1);
		usleep(1000);
	}
}

void	*monitor(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	watch(philos[0].rules, philos);
	return (0);
}
