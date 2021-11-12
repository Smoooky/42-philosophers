#include "philo.h"

t_fork *ft_add_fork(int id)
{
	t_fork			*new;
	pthread_mutex_t	*fork_mutex;

	new = (t_fork *)malloc(sizeof(t_fork));
	if (!new)
		exit(1);
	new->id = id;
	fork_mutex = malloc(sizeof (pthread_mutex_t));
	new->fork_mutex = fork_mutex;
}

t_philo	*ft_create_philo(int id)
{
	t_philo		*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		exit(1);
	new->id = id;
	new->next = NULL;
	new->prev = NULL;
	new->lfork = NULL;
	new->rfork = NULL;
	return (new);
}

t_philo *ft_init_philos(int amount)
{
	int		counter;
	t_philo	*new;
	t_philo	*first;
	t_philo *curr;

	counter = 2;
	first = ft_create_philo(1);
	first->lfork = ft_add_fork(1);
	first->rfork = ft_add_fork(2);
	curr = first;
	while (counter != amount)
	{
		new = ft_create_philo(counter);
		new->prev = curr;
		curr->next = new;
		new->lfork = new->prev->rfork;
		new->rfork = ft_add_fork(counter + 1);
		curr = curr->next;
		counter++;
	}
	new = ft_create_philo(counter);
	new->prev = curr;
	curr->next = new;
	new->next = first;
	first->prev = new;
	new->lfork = new->prev->rfork;
	new->rfork = new->next->lfork;
}

t_env *ft_input_proc(int argc, char **argv)
{
	t_env *env;

	env = malloc(sizeof(t_env));
	env->number_of_philos = atoi(argv[1]);
	env->to_die = atoi(argv[2]);
	env->to_eat = atoi(argv[3]);
	env->to_sleep = atoi(argv[4]);
	if (argc == 6)
		env->to_stop = atoi(argv[5]);
	else
		env->to_stop = 0;
	env->philos = ft_init_philos(env->number_of_philos);
	return (env);
}
