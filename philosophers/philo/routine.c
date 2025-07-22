/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/22 15:07:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo->rules, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo->rules, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo->rules, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo->rules, philo->id, "has taken a fork");
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!stop(philo->rules, -1))
	{
		take_fork(philo);
		print_action(philo->rules, philo->id, "is eating");
		last_meal(philo, now_ms());
		smart_sleep(philo->rules->t_eat, philo->rules);
		eat(philo, 1);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_action(philo->rules, philo->id, "is sleeping");
		smart_sleep(philo->rules->t_sleep, philo->rules);
		print_action(philo->rules, philo->id, "is thinking");
		usleep(1000);
	}
	return (0);
}
