/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:36:55 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/22 17:43:07 by yidemir          ###   ########.fr       */
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
	sem_t	*dead;
	sem_t	*everyone_ate;
	sem_t	*print;
	sem_t	*forks;
}	t_rules;

typedef struct s_philo
{
	pid_t		pid;
	int			id;
	int			eaten;
	long		last_meal;
	pthread_t	monitor_th;
	t_rules		*rules;
}	t_philo;

int		ft_atoi(char *str);
int		put_error(char *str1, char *str2);
long	now_ms(void);
void	smart_sleep(long dur_ms);
void	print_action(t_rules *rules, int id, const char *msg);

int		init_rules(t_rules *rules, char **argv);
int		init_philos(t_rules *rules, t_philo **philos);
void	start_philos(t_philo *p, int n);

void	clean_philos(t_philo *philos, int n);
void	clean_rules(t_rules *rules, int unlink);

void	routine(t_philo	*p);

#endif
