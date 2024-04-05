/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:07:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/05 16:52:45 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define RED "\033[31m"
# define NORMAL "\033[0m"

# define MAX_PHILOS 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int 			last_meal;
	int 			meals_eaten;
	int				nb_must_eat;
	int 			nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				start_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_philo_program
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_philo_program;


int		ft_atoi(const char *str);
int		check_args(t_philo_program *prog, char **argv);
int		check_if_nb(char *str);
int		ft_error(int nb);
void	init_args(t_philo_program *prog, char **argv);
void	*routine();
void	create_philos(t_philo_program *program, int philos);
void	init_philos(t_philo_program *program);
void	init_forks(t_philo_program *program);






# endif