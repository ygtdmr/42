/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:24:52 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/22 15:10:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	last_meal(t_philo *philo, int val)
{
	long	last_meal;

	pthread_mutex_lock(&philo->rules->last_meal);
	if (val >= 0)
		philo->last_meal = val;
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->rules->last_meal);
	return (last_meal);
}

int	eat(t_philo *philo, int add)
{
	int	eaten;

	if (philo->rules->must_eat == -1)
		return (0);
	pthread_mutex_lock(&philo->rules->eat);
	if (add > 0)
		philo->eaten++;
	eaten = philo->eaten;
	pthread_mutex_unlock(&philo->rules->eat);
	return (eaten);
}

int	stop(t_rules *rules, int val)
{
	int	is_stop;

	pthread_mutex_lock(&rules->stop);
	if (val >= 0)
		rules->is_stop = val > 0;
	is_stop = rules->is_stop;
	pthread_mutex_unlock(&rules->stop);
	return (is_stop);
}
