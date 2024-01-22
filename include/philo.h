
#ifndef PHILO_H
# define PHILO_H
#include <limits.h>
#include <stdio.h>


typedef struct s_philo
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int num_of_philos;
	int	nb_times_to_eat;

}	t_philo;

int check_if_nb(char *str);
int	ft_atoi(char *str);
#endif