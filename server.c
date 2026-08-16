/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:48:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/01/26 21:05:05 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static void	handle_sig(int sig)
{
	static unsigned char	byte;
	static int				lbit;

	if (sig == SIGUSR1)
		byte |= (1 << lbit);
	lbit++;
	if (lbit != 8)
		return ;
	write(1, &byte, 1);
	if (!byte)
		write(1, "\n", 1);
	lbit = 0;
	byte = 0;
}

int	main(void)
{
	if (signal(SIGUSR1, handle_sig) == SIG_ERR)
		return (1);
	if (signal(SIGUSR2, handle_sig) == SIG_ERR)
		return (1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
