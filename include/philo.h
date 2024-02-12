/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:32 by ecortes-          #+#    #+#             */
/*   Updated: 2024/02/12 15:38:39 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
#include <stdio.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_philo
{
	size_t			*nb_of_philos;
	size_t			*time_to_die;
	size_t			*time_to_eat;
	size_t			*time_to_sleep;
	size_t			*max_meals;
	pthread_t		thread;
	int				id;
	size_t				meals_eaten;
	size_t			last_meal;
	size_t			start_time;
	int				*dead;
	t_mutex	*r_fork;
	t_mutex	*l_fork;
	t_mutex	*write_lock;
	t_mutex	*dead_lock;
	t_mutex	*meal_lock;
}					t_philo;

typedef struct s_program
{
	size_t			nb_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t				max_meals;
	int				dead_flag;
	t_mutex	dead_lock;
	t_mutex	meal_lock;
	t_mutex	write_lock;
	t_philo	*philos;
	t_mutex	*forks;
}					t_program;

//utils
void *safe_malloc(size_t bytes);
int	ft_atoi(char *str);
size_t	get_current_time(void);
void ft_error(char *str);

//inits
int parse_argv(char **argv);
void init(t_program *program, char **argv);
void init_argv(t_program *prog, char **argv);
void init_philos(t_program *prog);
void init_mutex(t_program *program);


//main
void free_destroy(t_program *program);

//threads
void threads(t_program *program);
void eat(t_philo *philo);
void philosleep(t_philo *philo);
void think(t_philo *philo);

# endif