/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:48:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/01/26 20:35:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		d;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	d = 48 + n % 10;
	write(fd, &d, 1);
}

static void	handle_sig(int sig, siginfo_t *info, void *context)
{
	static unsigned char	byte;
	static int				lbit;

	if (!context)
		return ;
	if (sig == SIGUSR1)
		byte |= (1 << lbit);
	lbit++;
	if (lbit != 8)
		return ;
	write(1, &byte, 1);
	if (!byte)
	{
		write(1, "\n", 1);
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit(1);
	}
	lbit = 0;
	byte = 0;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return (1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
