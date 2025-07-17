/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/17 17:20:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	watch(t_rules *rules)
{
	int	status;
	int	eaten_cnt;

	eaten_cnt = 0;
	while (1)
	{
		if (rules->must_eat && eaten_cnt == rules->n_philo)
			break;
		if (waitpid(-1, &status, WNOHANG) > 0 && WEXITSTATUS(status) == 1)
			break;
		if (rules->must_eat && sem_wait(rules->everyone_ate) == 0)
			eaten_cnt++;
		usleep(1000);
	}
}

