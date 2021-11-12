#include "philo.h"

int	number_of_philosophers;
int	time_to_die;
int	time_to_eat;
int	time_to_sleep;
int	number_of_times_each_philosopher_must_eat;



void ft_eat(int id)
{
	if (id != 0 && id != number_of_philosophers)
	{
		pthread_mutex_lock(&fork[id])
	}
}

void ft_sleep(int id)
{

}

void ft_think(int id, int *is_dead)
{

}

void	*ft_philo(void *arg)
{
	int id;
	int is_dead;

	is_dead = 0;
	id = *(int*)arg;
	while(is_dead == 0)
	{
		ft_eat(id);
		ft_sleep(id);
		ft_think(id, &is_dead);
	}
	free(arg);
}

int	ft_start_simulation(int number_of_philosophers)
{
	pthread_mutex_t	forks[number_of_philosophers];
	pthread_mutex_t	printing;
	pthread_t		philos[number_of_philosophers];
	int 			i;
	int				*a;

	i = 0;
	while(i != number_of_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i != number_of_philosophers)
	{
		a = malloc(sizeof (int));
		*a = i;
		if (pthread_create(&philos[i], NULL, &ft_philo, a) != 0)
		{
			perror("Failed to create thread");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i != number_of_philosophers)
	{
		if (pthread_join(philos[i], NULL) != 0)
		{
			perror("Failed to join thread");
			return (1);
		}
		i++;
	}
}



int main(int argc, char **argv)
{
	t_env *env;

	if (argc == 5 || argc == 6)
		env = ft_input_proc(argc, argv);
	else
		printf("Program should have the same options: number_of_philosophers "
			   "time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	ft_start_simulation(number_of_philosophers);
	return 0;
}
