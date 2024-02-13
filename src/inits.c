/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:27:27 by ecortes-          #+#    #+#             */
/*   Updated: 2024/02/13 15:33:49 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int parse_argv(char **argv)
{
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0)
		return (printf("Invalid philosophers number\n"));
	if (ft_atoi(argv[2]) <= 0)
			return (printf("Invalid time to die\n"));
	if (ft_atoi(argv[3]) <= 0)
			return (printf("Invalid time to eat\n"));
	if (ft_atoi(argv[4]) <= 0)
		return (printf("Invalid time to sleep\n"));
	if (argv[5] && ft_atoi(argv[5]) < 0)
		return (printf("Invalid times must eat\n"));
	return (0);
}
void init(t_program *program, char **argv)
{
	program->dead_flag = 0;
	//pthread_mutex_init(&program->dead_lock, NULL);
	// pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	init_argv(program, argv);
	init_mutex(program);
	init_philos(program);
}

void init_argv(t_program *prog, char **argv)
{
	prog->philos = (t_philo *)safe_malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	prog->forks = (t_mutex *)safe_malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	prog->nb_of_philos = ft_atoi(argv[1]);
	prog->time_to_die = ft_atoi(argv[2]);
	prog->time_to_eat = ft_atoi(argv[3]);
	prog->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog->max_meals = ft_atoi(argv[5]);
}

void init_philos(t_program *prog)
{
	size_t i;

	i = 0;
	while (i < prog->nb_of_philos)
	{
		prog->philos[i].nb_of_philos = &prog->nb_of_philos;
		prog->philos[i].time_to_die = &prog->time_to_die;
		prog->philos[i].time_to_eat = &prog->time_to_eat;
		prog->philos[i].time_to_sleep = &prog->time_to_sleep;
		prog->philos[i].max_meals = &prog->max_meals;
		prog->philos[i].id = i + 1;
		prog->philos[i].meals_eaten = 0;
		prog->philos[i].write_lock = &prog->write_lock;
		prog->philos[i].meal_lock = &prog->meal_lock;
		prog->philos[i].dead_lock = &prog->dead_lock;
	//	prog->philos[i].l_fork = (t_mutex *)malloc(sizeof(t_mutex));
	//	prog->philos[i].r_fork = (t_mutex *)malloc(sizeof(t_mutex));
		prog->philos[i].l_fork = &(prog->forks[i]);
		prog->philos[i].dead = &prog->dead_flag;
		prog->philos[i].start_time = get_current_time();
		prog->philos[i].last_meal = get_current_time();
		if (i == 0)
			prog->philos[i].r_fork = &(prog->forks[prog->nb_of_philos -1]);
		else
			prog->philos[i].r_fork = &(prog->forks[i - 1]);
		i++;
	}
}

void init_mutex(t_program *program)
{
	size_t i;

	i = 0;
	while (i < program->nb_of_philos)
	{
		pthread_mutex_init(&(program->forks[i]), NULL);
		i++;
	}
}