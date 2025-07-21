/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/21 14:50:36 by yidemir          ###   ########.fr       */
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

static void	watch(t_rules *rules)
{
	int	status;
	int	eaten_cnt;

	eaten_cnt = 0;
	while (1)
	{
		if (rules->must_eat && (eaten_cnt == rules->n_philo))
			break ;
		if (waitpid(-1, &status, WNOHANG) > 0 && (WEXITSTATUS(status) == 1))
			break ;
		if (rules->must_eat && (sem_wait(rules->everyone_ate) == 0))
			eaten_cnt++;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;

	if (!validate_args(argc - 1, argv + 1))
		return (1);
	clean_rules(0, 1);
	init_rules(&rules, argv + 1);
	init_philos(&rules, &philos);
	start_philos(philos, rules.n_philo);
	watch(&rules);
	clean_philos(philos, rules.n_philo);
	clean_rules(&rules, 1);
	free(philos);
	return (0);
}
