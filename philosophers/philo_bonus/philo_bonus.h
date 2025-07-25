/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:55 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/25 06:00:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <semaphore.h>

typedef struct s_rules
{
	int		n_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	int		must_eat;
	long	start_ts;
	sem_t	*print;
	sem_t	*stop;
	sem_t	*died;
	sem_t	*eat;
	sem_t	*last_meal;
	sem_t	*forks;
}	t_rules;

typedef struct s_philo
{
	int			pid;
	int			id;
	int			eaten;
	long		last_meal;
	int			is_stop;
	pthread_t	routine_th;
	pthread_t	monitor_th;
	pthread_t	died_checker_th;
	t_rules		*rules;
}	t_philo;

int		ft_atoi(char *str);
int		put_error(char *str1, char *str2);
long	now_ms(void);
void	smart_sleep(long dur_ms, t_philo *philo);
void	print_action(t_philo *philo, char *msg);

int		init_rules(t_rules *rules, char **argv);
int		init_philos(t_rules *rules, t_philo **philos);
int		start_philos(t_philo *philos);
void	clean_sem(t_rules *rules, int unlink);

int		eat(t_philo *philo, int add);
long	last_meal(t_philo *philo, long val);
int		stop(t_philo *philo, int val);

void	*died_checker(void *arg);
void	*monitor(void *arg);
void	*routine(void *arg);
int		start_routine(t_philo *philo);

#endif
