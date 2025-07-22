/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/22 17:54:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_rules(t_rules *rules, char **argv)
{
	int	i;

	rules->n_philo = ft_atoi(*(argv++));
	rules->t_die = ft_atoi(*(argv++));
	rules->t_eat = ft_atoi(*(argv++));
	rules->t_sleep = ft_atoi(*(argv++));
	if (*argv)
		rules->must_eat = ft_atoi(*argv);
	else
		rules->must_eat = -1;
	rules->start_ts = now_ms();
	rules->stop = 0;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->n_philo);
	if (!rules->forks)
		return (put_error("malloc error", 0));
	if (pthread_mutex_init(&rules->print, 0))
		return (put_error("pthread_mutex_init error", 0));
	i = 0;
	while (i < rules->n_philo)
	{
		if (pthread_mutex_init(rules->forks + i++, 0))
			return (put_error("pthread_mutex_init error", 0));
	}
	return (1);
}

int	init_philos(t_rules *rules, t_philo **philos)
{
	int	i;

	(*philos) = malloc(sizeof(t_philo) * rules->n_philo);
	if (!(*philos))
		return (put_error("malloc error", 0));
	i = 0;
	while (i < rules->n_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eaten = 0;
		(*philos)[i].last_meal = rules->start_ts;
		(*philos)[i].rules = rules;
		(*philos)[i].left_fork = rules->forks + i;
		if ((i + 1) == rules->n_philo)
			(*philos)[i].right_fork = rules->forks;
		else
			(*philos)[i].right_fork = rules->forks + (i + 1);
		if (pthread_create(&((*philos)[i].th), 0, routine, (*philos) + i))
			return (put_error("pthread_create error", 0));
		i++;
	}
	return (1);
}

void	clean_rules(t_rules rules)
{
	int	i;

	i = 0;
	while (i < rules.n_philo)
		pthread_mutex_destroy(rules.forks + i++);
	pthread_mutex_destroy(&rules.print);
	free(rules.forks);
}

void	clean_philos(t_philo *philos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_unlock(philos[i].left_fork);
		pthread_mutex_unlock(philos[i].right_fork);
		pthread_join(philos[i++].th, 0);
	}
}
