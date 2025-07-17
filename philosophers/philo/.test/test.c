/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 07:01:56 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/17 08:53:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_rules(t_rules rules)
{
	int	i;

	printf("philosophers\t=> %d\n\
time_to_die\t=> %ld\n\
time_to_eat\t=> %ld\n\
time_to_sleep\t=> %ld\n\
must_eat\t=> %d\n\
start_ts\t=> %ld\n\
stop\t\t=> %d\n", \
	rules.n_philo, rules.t_die, rules.t_eat, rules.t_sleep, rules.must_eat, \
	rules.start_ts, rules.stop);

	i = 0;
	while (i < rules.n_philo)
	{
		printf("fork [%d]\t=> %p\n", i + 1, rules.forks + i);
		i++;
	}
	printf("\n");
}

void	print_philo(t_philo philo)
{
	printf("id\t\t=> %d\n\
eaten\t\t=> %d\n\
last_meal\t=> %ld\n\
thread\t\t=> %ld\n\
fork\t\t=> %p\n\
next_fork\t=> %p\n\
rules\t\t=> %p\n\n", \
	philo.id, philo.eaten, philo.last_meal, philo.th, \
	philo.fork, philo.next_fork, philo.rules);
}

void	print_philos(t_philo *philos, int n)
{
	while (n--)
		print_philo(*philos++);
}
