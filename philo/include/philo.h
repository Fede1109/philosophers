/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:07:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/20 16:13:29 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define RED "\033[0;31m"
# define SLEEP "\033[0;95m"
# define DIE "\033[0;30m"
# define EAT "\033[0;93m"
# define THINK "\033[0;94m"
# define RESET "\033[0m"
# define MAX_PHILOS 200

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
	size_t			*time_to_die;
	size_t			*time_to_eat;
	size_t			*time_to_sleep;
	int				*nb_must_eat;
	int				*nb_philos;
	int				*dead_flag;
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	size_t			start_time;
}	t_philo;

typedef struct s_philo_program
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	int				nb_philos;
	int				nb_must_eat;
	int				dead_flag;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	t_philo			*philos;
}	t_philo_program;

	/*	aux functions.c	*/
int		ft_atoi(const char *str);
int		ft_error(int nb);
size_t	get_current_time(void);
void	print_msg(char *str, t_philo *philo, char *action);
	/*	check_args.c	*/
int		check_if_nb(char *str);
int		check_args(t_philo_program *prog, char **argv);
void	init_prog(t_philo_program *prog, char **argv);
	/*	init.c	*/
void	create_philos(t_philo_program *program, int philos);
void	init_philos(t_philo_program *program, char **argv);
void	init_forks(t_philo_program *prog, int philos);
void	init_all(t_philo_program *prog, char **argv);
	/*	routine.c	*/
void	*routine(void *pointer);
void	destroy_mutex(t_philo_program *prog);
void	start_routine(t_philo_program *prog, int philos);
	/*	time.c	*/
int		ft_sleep(size_t milliseconds);
	/*	routine_actions.c	*/
void	ph_sleep(t_philo *philo);
void	ph_eat(t_philo *philo);
void	ph_think(t_philo *philo);
	/*	die.c	*/
void	*monitoring(void *ptr);
int		dead_loop(t_philo *philo);
int		check_philo_death(t_philo *philo);

#endif