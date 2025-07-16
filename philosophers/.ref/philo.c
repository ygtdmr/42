/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/16 14:29:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	validate_args(int argc, char **argv)
{
	int	tmp;

	if (!(argc == 4 || argc == 5))
		return (put_error("Argument count is invalid", 0));
	while (*argv)
	{
		tmp = atoi_positive(*argv);
		if (tmp == -1 || !tmp)
			return (put_error(*argv, ": Argument is invalid"));
		argv++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_rules		r;
	t_philo		*ph;
	pthread_t	mon_th;

	if (!validate_args(argc - 1, argv + 1))
		return (1);
	init_rules(&r, argv + 1);
	init_mutexes(&r);
	ph = init_philos(&r);
	r.start_ts = now_ms();
	start_threads(ph, &r);
	pthread_create(&mon_th, 0, monitor, ph);
	pthread_join(mon_th, 0);
	join_threads(ph, &r);
	destroy_mutexes(&r);
	free(ph);
	return (0);
}
