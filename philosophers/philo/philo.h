/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:55 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/22 14:53:34 by yidemir          ###   ########.fr       */
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
	int				is_stop;
	pthread_mutex_t	print;
	pthread_mutex_t	stop;
	pthread_mutex_t	eat;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	*forks;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				eaten;
	long			last_meal;
	pthread_t		th;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_rules			*rules;
}	t_philo;

int		ft_atoi(char *str);
int		put_error(char *str1, char *str2);
long	now_ms(void);
void	smart_sleep(long dur_ms, t_rules *rules);
void	print_action(t_rules *rules, int id, const char *msg);

int		init_rules(t_rules *rules, char **argv);
int		init_philos(t_rules *rules, t_philo **philos);
void	start_philos(t_philo *philos, int n);
void	clean_rules(t_rules rules);
void	clean_philos(t_philo *philos, int n);

int		eat(t_philo *philo, int add);
long	last_meal(t_philo *philo, int val);
int		stop(t_rules *rules, int val);

void	*routine(void *arg);
void	*monitor(void *arg);

#endif
