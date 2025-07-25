/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/25 11:16:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*died_checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	sem_wait(philo->rules->died);
	if (!stop(philo, -1))
	{
		stop(philo, 1);
		sem_post(philo->rules->died);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!stop(philo, -1))
	{
		if ((now_ms() - last_meal(philo, -1)) > philo->rules->t_die)
		{
			print_action(philo, "died");
			sem_wait(philo->rules->print);
			sem_post(philo->rules->died);
			if (philo->rules->n_philo == 1)
				sem_post(philo->rules->forks);
			break ;
		}
		if (philo->rules->must_eat != -1 && \
(eat(philo, 0) == philo->rules->must_eat))
		{
			stop(philo, 1);
			sem_post(philo->rules->died);
			break ;
		}
		usleep(1000);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!stop(philo, -1))
	{
		sem_wait(philo->rules->forks);
		print_action(philo, "has taken a fork");
		sem_wait(philo->rules->forks);
		print_action(philo, "has taken a fork");
		print_action(philo, "is eating");
		last_meal(philo, now_ms());
		smart_sleep(philo->rules->t_eat, philo);
		eat(philo, 1);
		sem_post(philo->rules->forks);
		sem_post(philo->rules->forks);
		print_action(philo, "is sleeping");
		smart_sleep(philo->rules->t_sleep, philo);
		print_action(philo, "is thinking");
		usleep(1000);
	}
	return (0);
}

int	start_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	if (pthread_create(&philo->died_checker_th, 0, died_checker, philo))
		return (put_error("died_checker", ": pthread_create error"));
	if (pthread_create(&philo->monitor_th, 0, monitor, philo))
		return (put_error("monitor", ": pthread_create error"));
	if (pthread_create(&philo->routine_th, 0, routine, philo))
		return (put_error("routine", ": pthread_create error"));
	pthread_join(philo->died_checker_th, 0);
	sem_post(philo->rules->complete);
	pthread_join(philo->monitor_th, 0);
	pthread_join(philo->routine_th, 0);
	return (1);
}
