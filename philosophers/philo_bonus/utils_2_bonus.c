/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/17 19:11:26 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_rules(t_rules *rules, char **argv)
{
	rules->n_philo = ft_atoi(*(argv++));
	rules->t_die = ft_atoi(*(argv++));
	rules->t_eat = ft_atoi(*(argv++));
	rules->t_sleep = ft_atoi(*(argv++));
	if (*argv)
		rules->must_eat = ft_atoi(*argv);
	else
		rules->must_eat = 0;
	rules->start_ts = now_ms();
	rules->forks = sem_open("/philo_forks", O_CREAT, 0644, rules->n_philo);
	rules->print = sem_open("/philo_print", O_CREAT, 0644, 1);
	rules->dead = sem_open("/philo_dead", O_CREAT, 0644, 1);
	rules->everyone_ate = sem_open("/philo_ate", O_CREAT, 0644, 0);
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
		(*philos)[i].id = i + 1;
		(*philos)[i].eaten = 0;
		(*philos)[i].last_meal = rules->start_ts;
		(*philos)[i].rules = rules;
		i++;
	}
}

void	start_philos(t_philo *philos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			routine(&philos[i]);
		i++;
	}
}

void	clean_philos(t_philo *philos, int n)
{
	int	i;

	i = 0;
	while (i < n)
		kill(philos[i++].pid, SIGKILL);
}

void	clean_rules(t_rules *rules)
{
	sem_close(rules->forks);
	sem_close(rules->print);
	sem_close(rules->dead);
	sem_close(rules->everyone_ate);
	sem_unlink("/philo_dead");
	sem_unlink("/philo_ate");
	sem_unlink("/philo_print");
	sem_unlink("/philo_forks");
}
