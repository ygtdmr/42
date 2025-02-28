/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:46:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/01/26 21:01:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_pid;

static int	ft_atoi(const char *str)
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

static void	send_signal(int bit)
{
	int	sig;

	if (bit == 1)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	if (kill(g_pid, sig) == -1)
	{
		write(1, "Error when send signal.\n", 24);
		exit(1);
	}
	usleep(500);
}

static void	send_message(char *s)
{
	int	i;
	int	bit;

	i = 0;
	while (1)
	{
		if (i > 7)
		{
			if (!*s)
				break ;
			s++;
			i = 0;
			continue ;
		}
		bit = *s >> i++ & 1;
		send_signal(bit);
	}
}

int	main(int argc, char *argv[])
{
	g_pid = ft_atoi(argv[1]);
	if (!g_pid || argc != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	send_message(argv[2]);
	return (0);
}
