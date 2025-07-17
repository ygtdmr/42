/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/17 19:12:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*monitor(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)arg;
	rules = philo->rules;
	while (1)
	{
		if ((now_ms() - philo->last_meal) > rules->t_die)
		{
			sem_wait(rules->dead);
			print_action(philo->rules, philo->id, "died");
			clean_rules(rules);
			exit(1);
		}
		usleep(1000);
	}
	return (0);
}

void	routine(t_philo	*p)
{
	pthread_create(&p->monitor_th, 0, monitor, p);
	while (1)
	{
		if (p->rules->must_eat && ++p->eaten == p->rules->must_eat)
		{
			sem_post(p->rules->everyone_ate);
			clean_rules(p->rules);
			exit(0);
		}
		print_action(p->rules, p->id, "is thinking");
		sem_wait(p->rules->forks);
		sem_wait(p->rules->forks);
		print_action(p->rules, p->id, "has taken a fork");
		print_action(p->rules, p->id, "has taken a fork");
		print_action(p->rules, p->id, "is eating");
		p->last_meal = now_ms();
		smart_sleep(p->rules->t_eat);
		if (p->rules->must_eat)
			p->eaten++;
		sem_post(p->rules->forks);
		sem_post(p->rules->forks);
		print_action(p->rules, p->id, "is sleeping");
		smart_sleep(p->rules->t_sleep);
	}
}
