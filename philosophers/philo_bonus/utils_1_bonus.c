/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:42:12 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/26 12:05:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	put_error(char *str1, char *str2)
{
	size_t	len;

	len = 0;
	while (str1 && str1[len])
		len++;
	write(2, "philo: ", 7);
	if (len)
		write(2, str1, len);
	len = 0;
	while (str2 && str2[len])
		len++;
	if (len)
		write(2, str2, len);
	write(2, "\n", 1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	s;
	int	r;

	s = 1;
	r = 0;
	while (*str == 32 || *str == 9 || (*str >= 10 && *str <= 13))
		str++;
	if (*str == 45)
		s = -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if (r > 0)
			r *= 10;
		r += (*str - 48);
		str++;
	}
	return (r * s);
}

long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	smart_sleep(long dur_ms, t_philo *philo)
{
	long	start;

	start = now_ms();
	while (!stop(philo, -1) && (now_ms() - start < dur_ms))
		usleep(1000);
}

void	print_action(t_philo *philo, char *msg)
{
	sem_wait(philo->rules->print);
	if (!stop(philo, -1))
		printf("%ld %d %s\n", \
now_ms() - philo->rules->start_ts, philo->id, msg);
	if (ft_strncmp(msg, "died", 4) != 0)
		sem_post(philo->rules->print);
}
