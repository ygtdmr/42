/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:55 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/17 09:16:35 by yidemir          ###   ########.fr       */
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
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				eaten;
	long			last_meal;
	pthread_t		th;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*next_fork;
	t_rules			*rules;
}	t_philo;

int		ft_atoi(char *str);
int		put_error(char *str1, char *str2);
long	now_ms(void);
void	smart_sleep(long dur_ms, t_rules *r);
void	print_action(t_rules *r, int id, const char *msg);

void	init_rules(t_rules *rules, char **argv);
void	init_philos(t_rules *rules, t_philo **philos);
void	start_philos(t_philo *philos, int n);
void	clean_rules(t_rules rules);
void	clean_philos(t_philo *philos, int n);

void	*routine(void *arg);
void	*monitor(void *arg);

#endif
