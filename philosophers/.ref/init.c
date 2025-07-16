/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:59:02 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/16 14:01:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_rules *r)
{
	int	i;

	r->forks = malloc(sizeof(pthread_mutex_t) * r->n_philo);
	if (!r->forks)
		return (0);
	if (pthread_mutex_init(&r->print, NULL))
	{
		free(r->forks);
		return (0);
	}
	i = 0;
	while (i < r->n_philo)
	{
		if (pthread_mutex_init(&r->forks[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&r->forks[i]);
			pthread_mutex_destroy(&r->print);
			free(r->forks);
			return (0);
		}
		i++;
	}
	return (1);
}

t_philo	*init_philos(t_rules *r)
{
	t_philo	*p;
	int		i;

	p = malloc(sizeof(t_philo) * r->n_philo);
	if (!p)
		return (0);
	i = 0;
	while (i < r->n_philo)
	{
		p[i].id = i + 1;
		p[i].eaten = 0;
		p[i].last_meal = r->start_ts;
		p[i].lfork = &r->forks[i];
		p[i].rfork = &r->forks[(i + 1) % r->n_philo];
		if (p[i].id % 2 == 0)
		{
			p[i].lfork = &r->forks[(i + 1) % r->n_philo];
			p[i].rfork = &r->forks[i];
		}
		p[i].r = r;
		i++;
	}
	return (p);
}
