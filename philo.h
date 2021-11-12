#ifndef PHILOSOPHERS_PHILO_H
#define PHILOSOPHERS_PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
	int		id;
	int is_eating;
	unsigned long long limit;
	unsigned long long last_eat;
	int	l_fork;
	int r_fork;
	int eat_count;
	struct s_state *state;
	pthread_mutex_t mutex;
	pthread_mutex_t eat_m;
}			t_philo;

typedef struct s_env
{
	int				number_of_philos;

	unsigned long long	to_die;
	unsigned long long	to_eat;
	unsigned long long	to_sleep;
	int				to_stop;
	unsigned long long	start; //why
	t_philo			*philos;
	pthread_mutex_t *forks_m;
	pthread_mutex_t write_m;
	pthread_mutex_t dead_m
}					t_env;


t_env *ft_input_proc(int argc, char **argv);

#endif //PHILOSOPHERS_PHILO_H
