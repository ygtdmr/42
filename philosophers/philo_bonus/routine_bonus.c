/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/21 13:07:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->rules->dead);
		if ((now_ms() - philo->last_meal) > philo->rules->t_die)
		{
			print_action(philo->rules, philo->id, "died");
			sem_wait(philo->rules->print);
			while (1 + philo->rules->n_philo--)
				sem_post(philo->rules->everyone_ate);
			clean_rules(philo->rules, 0);
			exit(1);
		}
		sem_post(philo->rules->dead);
		if (philo->rules->must_eat && (philo->eaten == philo->rules->must_eat))
		{
			sem_post(philo->rules->everyone_ate);
			clean_rules(philo->rules, 0);
			exit(0);
		}
		usleep(1000);
	}
	return (0);
}

void	routine(t_philo	*p)
{
	pthread_create(&p->monitor_th, 0, monitor, p);
	pthread_detach(p->monitor_th);
	if (p->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		sem_wait(p->rules->forks);
		print_action(p->rules, p->id, "has taken a fork");
		sem_wait(p->rules->forks);
		print_action(p->rules, p->id, "has taken a fork");
		print_action(p->rules, p->id, "is eating");
		sem_wait(p->rules->dead);
		p->last_meal = now_ms();
		sem_post(p->rules->dead);
		smart_sleep(p->rules->t_eat);
		if (p->rules->must_eat)
			p->eaten++;
		sem_post(p->rules->forks);
		sem_post(p->rules->forks);
		print_action(p->rules, p->id, "is sleeping");
		smart_sleep(p->rules->t_sleep);
		print_action(p->rules, p->id, "is thinking");
		usleep(1000);
	}
}
