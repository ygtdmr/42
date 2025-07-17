/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/17 18:36:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	t_rules	rules;
	t_philo	*philos;

	if (!validate_args(argc - 1, argv + 1))
		return (1);
	clean_rules(&rules);
	init_rules(&rules, argv + 1);
	init_philos(&rules, &philos);
	start_philos(philos, rules.n_philo);
	watch(&rules);
	clean_philos(philos, rules.n_philo);
	clean_rules(&rules);
	free(philos);
	return (0);
}
