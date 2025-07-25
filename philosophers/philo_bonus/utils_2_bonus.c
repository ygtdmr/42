/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/25 06:30:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_sem(t_rules *rules, int unlink)
{
	if (rules)
	{
		sem_close(rules->print);
		sem_close(rules->stop);
		sem_close(rules->died);
		sem_close(rules->eat);
		sem_close(rules->last_meal);
		sem_close(rules->forks);
	}
	if (unlink)
	{
		sem_unlink("/philo_print");
		sem_unlink("/philo_stop");
		sem_unlink("/philo_died");
		sem_unlink("/philo_eat");
		sem_unlink("/philo_last_meal");
		sem_unlink("/philo_forks");
	}
}

static int	init_sem(t_rules *rules)
{
	clean_sem(0, 1);
	rules->print = sem_open("/philo_print", O_CREAT, 0644, 1);
	rules->stop = sem_open("/philo_stop", O_CREAT, 0644, 1);
	rules->died = sem_open("/philo_died", O_CREAT, 0644, 0);
	rules->eat = sem_open("/philo_eat", O_CREAT, 0644, 1);
	rules->last_meal = sem_open("/philo_last_meal", O_CREAT, 0644, 1);
	rules->forks = sem_open("/philo_forks", O_CREAT, 0644, rules->n_philo);
	if (!rules->print || !rules->stop || !rules->died || \
!rules->eat || !rules->last_meal || !rules->forks)
		return (put_error("sem_open failed", 0));
	return (1);
}

int	init_rules(t_rules *rules, char **argv)
{
	rules->n_philo = ft_atoi(*(argv++));
	rules->t_die = ft_atoi(*(argv++));
	rules->t_eat = ft_atoi(*(argv++));
	rules->t_sleep = ft_atoi(*(argv++));
	if (*argv)
		rules->must_eat = ft_atoi(*argv);
	else
		rules->must_eat = -1;
	rules->start_ts = now_ms();
	return (init_sem(rules));
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
		(*philos)[i].is_stop = 0;
		(*philos)[i].last_meal = rules->start_ts;
		(*philos)[i].rules = rules;
		i++;
	}
	return (1);
}

int	start_philos(t_philo *philos)
{
	int	status;
	int	i;

	i = 0;
	while (i < philos->rules->n_philo)
	{
		philos[i].pid = fork();
		if (philos[i].pid == 0)
		{
			philos->rules->start_ts = now_ms();
			philos[i].last_meal = philos->rules->start_ts;
			status = start_routine(philos + i);
			clean_sem(philos->rules, 0);
			free(philos);
			exit(!status);
		}
		else if (philos[i].pid > 0)
			i++;
		else
			return (put_error("fork error", 0));
	}
	return (1);
}
