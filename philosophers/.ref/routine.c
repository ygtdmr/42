/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:25:00 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/16 12:26:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(1000);
	while (!p->r->stop)
	{
		print_action(p->r, p->id, "is thinking");
		pthread_mutex_lock(p->lfork);
		print_action(p->r, p->id, "has taken a fork");
		pthread_mutex_lock(p->rfork);
		print_action(p->r, p->id, "has taken a fork");

		print_action(p->r, p->id, "is eating");
		p->last_meal = now_ms();
		smart_sleep(p->r->t_eat, p->r);
		p->eaten++;

		pthread_mutex_unlock(p->rfork);
		pthread_mutex_unlock(p->lfork);

		print_action(p->r, p->id, "is sleeping");
		smart_sleep(p->r->t_sleep, p->r);
	}
	return (0);
}
