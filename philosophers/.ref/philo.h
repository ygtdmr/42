/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:55 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/16 14:40:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_rules
{
	int				n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				must_eat;
	long			start_ts;
	int				stop;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
} t_rules;

typedef struct s_philo
{
	int				id;
	int				eaten;
	long			last_meal;
	pthread_t		th;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	t_rules			*r;
} t_philo;

int		put_error(char *str1, char *str2);
int		atoi_positive(char *str);

long	now_ms(void);
void	smart_sleep(long dur_ms, t_rules *r);
void	print_action(t_rules *r, int id, const char *msg);

void	*routine(void *arg);
void	*monitor(void *arg);

t_philo	*init_philos(t_rules *r);
int		init_mutexes(t_rules *r);
void	init_rules(t_rules *r, char **argv);

int		start_threads(t_philo *ph, t_rules *r);
int		join_threads(t_philo *ph, t_rules *r);
void	destroy_mutexes(t_rules *r);

#endif
