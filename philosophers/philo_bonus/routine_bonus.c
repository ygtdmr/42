/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/20 19:26:35 by yidemir          ###   ########.fr       */
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
		sem_wait(rules->dead);
		if ((now_ms() - philo->last_meal) > rules->t_die)
		{
			print_action(philo->rules, philo->id, "died");
			sem_wait(rules->print);
			sem_post(rules->everyone_ate);
			clean_rules(rules, 0);
			exit(1);
		}
		sem_post(rules->dead);
		if (rules->must_eat && philo->eaten == rules->must_eat)
		{
			sem_post(rules->everyone_ate);
			clean_rules(rules, 0);
			exit(0);
		}
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
		print_action(p->rules, p->id, "is thinking");
		sem_wait(p->rules->forks);
		print_action(p->rules, p->id, "has taken a fork");
		sem_wait(p->rules->forks);
		print_action(p->rules, p->id, "has taken a fork");
		print_action(p->rules, p->id, "is eating");
		sem_wait(p->rules->dead);
		p->last_meal = now_ms();
		sem_post(p->rules->dead);
		if (p->rules->must_eat)
			p->eaten++;
		smart_sleep(p->rules->t_eat);
		sem_post(p->rules->forks);
		sem_post(p->rules->forks);
		print_action(p->rules, p->id, "is sleeping");
		smart_sleep(p->rules->t_sleep);
	}
}
