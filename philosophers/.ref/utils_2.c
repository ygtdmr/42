/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/17 09:06:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_threads(t_philo *ph, t_rules *r)
{
	int	i;

	i = 0;
	while (i < r->n_philo)
	{
		ph[i].last_meal = now_ms();
		if (pthread_create(&ph[i].th, 0, &routine, &ph[i]))
		{
			r->stop = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	join_threads(t_philo *ph, t_rules *r)
{
	int	i;

	i = 0;
	while (i < r->n_philo)
	{
		if (pthread_join(ph[i].th, 0))
			return (0);
		i++;
	}
	return (1);
}

void	destroy_mutexes(t_rules *r)
{
	int	i;

	i = 0;
	while (i < r->n_philo)
		pthread_mutex_destroy(&r->forks[i++]);
	pthread_mutex_destroy(&r->print);
	free(r->forks);
}

void	init_rules(t_rules *r, char **argv)
{
	r->n_philo = ft_atoi(*(argv++));
	r->t_die = ft_atoi(*(argv++));
	r->t_eat = ft_atoi(*(argv++));
	r->t_sleep = ft_atoi(*(argv++));
	if (*argv)
		r->must_eat = ft_atoi(*argv);
	r->start_ts = 0;
	r->stop = 0;
	r->forks = 0;
}
