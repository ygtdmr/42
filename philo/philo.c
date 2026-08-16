/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/23 14:32:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	validate_args(int argc, char **argv)
{
	if (!(argc == 4 || argc == 5))
		return (put_error("Argument count is invalid: \
<number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]", 0));
	while (*argv)
	{
		if (ft_atoi(*argv) <= 0)
			return (put_error(*argv, ": Argument is invalid"));
		argv++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_rules		rules;
	t_philo		*philos;
	pthread_t	monitor_th;

	if (!validate_args(argc - 1, argv + 1))
		return (1);
	if (!init_rules(&rules, argv + 1))
		return (1);
	if (!init_philos(&rules, &philos))
		return (1);
	pthread_create(&monitor_th, 0, monitor, philos);
	pthread_join(monitor_th, 0);
	clean_philos(philos, rules.n_philo);
	clean_rules(&rules);
	free(philos);
	return (0);
}
