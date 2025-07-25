/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:24:52 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/25 06:00:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	last_meal(t_philo *philo, long val)
{
	long	last_meal;

	sem_wait(philo->rules->last_meal);
	if (val >= 0)
		philo->last_meal = val;
	last_meal = philo->last_meal;
	sem_post(philo->rules->last_meal);
	return (last_meal);
}

int	eat(t_philo *philo, int add)
{
	int	eaten;

	if (philo->rules->must_eat == -1)
		return (0);
	sem_wait(philo->rules->eat);
	if (add > 0)
		philo->eaten++;
	eaten = philo->eaten;
	sem_post(philo->rules->eat);
	return (eaten);
}

int	stop(t_philo *philo, int val)
{
	int	is_stop;

	sem_wait(philo->rules->stop);
	if (val >= 0)
		philo->is_stop = val > 0;
	is_stop = philo->is_stop;
	sem_post(philo->rules->stop);
	return (is_stop);
}
