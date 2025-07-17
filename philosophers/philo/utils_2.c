/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/17 09:15:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_rules(t_rules *rules, char **argv)
{
	int	i;

	rules->n_philo = ft_atoi(*(argv++));
	rules->t_die = ft_atoi(*(argv++));
	rules->t_eat = ft_atoi(*(argv++));
	rules->t_sleep = ft_atoi(*(argv++));
	if (*argv)
		rules->must_eat = ft_atoi(*argv);
	else
		rules->must_eat = 0;
	rules->start_ts = now_ms();
	rules->stop = 0;
	pthread_mutex_init(&rules->print, 0);
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->n_philo);
	if (!rules->forks)
		return ;
	i = 0;
	while (i < rules->n_philo)
		pthread_mutex_init(rules->forks + i++, 0);
}

void	init_philos(t_rules *rules, t_philo **philos)
{
	int	i;

	(*philos) = malloc(sizeof(t_philo) * rules->n_philo);
	if (!(*philos))
		return ;
	i = 0;
	while (i < rules->n_philo)
	{
		(*philos)[i].id = i;
		(*philos)[i].eaten = 0;
		(*philos)[i].last_meal = 0;
		(*philos)[i].rules = rules;
		pthread_create(&((*philos)[i].th), 0, routine, (*philos) + i);
		(*philos)[i].fork = rules->forks + i;
		if ((i + 1) == rules->n_philo)
			(*philos)[i].next_fork = rules->forks;
		else
			(*philos)[i].next_fork = rules->forks + (i + 1);
		i++;
	}
}

void	start_philos(t_philo *philos, int n)
{
	int	i;

	i = 0;
	while (i < n)
		pthread_join(philos[i++].th, 0);
}

void	clean_rules(t_rules rules)
{
	int	i;

	i = 0;
	while (i < rules.n_philo)
		pthread_mutex_destroy(rules.forks + i++);
	free(rules.forks);
	pthread_mutex_destroy(&rules.print);
}

void	clean_philos(t_philo *philos, int n)
{
	int	i;

	i = 0;
	while (i < n)
		pthread_detach(philos[i++].th);
	free(philos);
}
