/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/25 06:30:05 by yidemir          ###   ########.fr       */
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

static void	wait_philos(t_philo *philos)
{
	int	n;

	n = philos->rules->n_philo;
	while (n)
		waitpid(philos[--n].pid, 0, 0);
}

int	main(int argc, char **argv)
{
	t_rules		rules;
	t_philo		*philos;

	if (!validate_args(argc - 1, argv + 1))
		return (1);
	if (!init_rules(&rules, argv + 1))
		return (1);
	if (!init_philos(&rules, &philos))
		return (1);
	if (!start_philos(philos))
		return (1);
	wait_philos(philos);
	clean_sem(&rules, 1);
	free(philos);
	return (0);
}
