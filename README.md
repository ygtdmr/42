*This project has been created as part of the 42 curriculum by ygtdmr.*

# Philosophers

## Description

This branch contains both variants of the dining philosophers simulation.

- philo models philosophers as POSIX threads sharing fork mutexes. It starts a monitor thread, tracks eating progress, and reports deaths and completion.
- philo_bonus models philosophers as processes and coordinates shared resources with POSIX semaphores. It waits for child processes and monitors completion through semaphores.

Both programs validate positive numeric arguments and accept the same simulation parameters. The source is split into philo and philo_bonus, each with its own Makefile and header.

## Instructions

Build the mandatory threaded version and the process/semaphore version independently:

~~~sh
make -C philo
make -C philo_bonus
~~~

Run either executable with:

~~~sh
./philo/philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
./philo_bonus/philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
~~~

Times are passed as positive integer values in the program's time unit. Each Makefile provides all, clean, fclean, and re. The implementation requires pthread support for philo and POSIX semaphore/process support for philo_bonus.

## Resources

- [POSIX pthreads](https://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutex_lock.html)
- [POSIX semaphore](https://pubs.opengroup.org/onlinepubs/9699919799/functions/sem_wait.html)
- [POSIX waitpid](https://pubs.opengroup.org/onlinepubs/9699919799/functions/wait.html)
- The 42 Philosophers subject is the reference for the simulation rules and timing requirements.

### AI Usage

AI was used during the repository split to inspect the thread and semaphore implementations, verify the two Makefile entry points, and draft this README. The original simulation code was not claimed to be AI-generated.

