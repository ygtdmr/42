/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/16 14:47:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_rules(t_rules *r, char **argv)
{
	r->n_philo = atoi_positive(*(argv++));
	r->t_die = atoi_positive(*(argv++));
	r->t_eat = atoi_positive(*(argv++));
	r->t_sleep = atoi_positive(*(argv++));
	if (*argv)
		r->must_eat = atoi_positive(*argv);
	r->start_ts = 0;
	r->stop = 0;
	r->forks = 0;
}
