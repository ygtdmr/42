/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:57:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/16 13:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t f1;
pthread_mutex_t f2;
	
void	*test(void *arg)
{
	int	tmp;
	int	*i;

	i = (int *)arg;
	tmp = 0;
	while (tmp++ < 1000000)
	{
		pthread_mutex_lock(&f1);
		(*i)++;
		pthread_mutex_unlock(&f1);
	}
}

int	main()
{
	pthread_t		p1;
	pthread_t		p2;
	int				i;

	i = 0;
	pthread_mutex_init(&f1, 0);
	pthread_mutex_init(&f2, 0);

	pthread_create(&p1, 0, test, &i);
	pthread_create(&p2, 0, test, &i);

    pthread_join(p1, 0);
    pthread_join(p2, 0);

	pthread_mutex_destroy(&f1);
	pthread_mutex_destroy(&f2);
	printf("result => %i\n", i);
	return (0);
}
