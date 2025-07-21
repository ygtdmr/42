/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/21 13:30:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(1000);
	while (!p->rules->stop)
	{
		pthread_mutex_lock(p->left_fork);
		print_action(p->rules, p->id, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
		print_action(p->rules, p->id, "has taken a fork");
		print_action(p->rules, p->id, "is eating");
		p->last_meal = now_ms();
		smart_sleep(p->rules->t_eat, p->rules);
		if (p->rules->must_eat)
			p->eaten++;
		pthread_mutex_unlock(p->left_fork);
		pthread_mutex_unlock(p->right_fork);
		print_action(p->rules, p->id, "is sleeping");
		smart_sleep(p->rules->t_sleep, p->rules);
		print_action(p->rules, p->id, "is thinking");
		usleep(1000);
	}
	return (0);
}
