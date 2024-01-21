
#ifndef PHILO_H
# define PHILO_H
#include <limits.h>


typedef struct s_philo
{
	int num_of_philos;
	int	times_to_eat;

}	t_philo;

int check_if_nb(char *str);
int	ft_atoi(char *str);
#endif