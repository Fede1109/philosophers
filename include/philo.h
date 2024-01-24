
#ifndef PHILO_H
# define PHILO_H
#include <limits.h>
#include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mutex;

typedef struct s_philo
{
	int				id;
	size_t			*time_to_die;
	size_t			*time_to_eat;
	size_t			*time_to_sleep;
	int 			*num_of_philos;
	int				nb_times_to_eat;
	int				meals_eaten;
	size_t			last_meal;
	size_t			start_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;


typedef struct s_program
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int 			num_of_philos;
	int				dead_flag;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
	t_mutex			*forks;

}	t_program;

int check_if_nb(char *str);
int	ft_atoi(char *str);
#endif