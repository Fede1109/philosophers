/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:27:27 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/17 20:01:56 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int parse_argv(char **argv)
{
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) <= 0)
		return (write(2, "Invalid philosophers number\n", 29), 1);
	if (ft_atoi(argv[2]) <= 0)
			return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0)
			return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0)
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argv[5] && ft_atoi(argv[5]) < 0)
		return (write(2, "Invalid times must eat\n",51), 1);
	return (0);
}
void init(t_program *program, char **argv)
{
	program->dead_flag = 0;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	init_argv(program, argv[1]);
	init_philos(program);
	init_mutex(program);
}

void init_argv(t_program *prog, char *argv)
{
	prog->philos = (t_program *)safe_malloc(sizeof(t_philo) * ft_atoi(argv));
	prog->nb_of_philos = ft_atoi(argv[1]);
	prog->time_to_die = ft_atoi(argv[2]);
	prog->time_to_eat = ft_atoi(argv[3]);
	prog->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog->max_meals = ft_atoi(argv[5]);
}

void init_philos(t_program *prog)
{
	int i;

	i = 0;
	while (i < ft_atoi)
	{
		prog->philos[i].id = ++i;
		prog->philos[i].eating = 0;
		prog->philos[i].meals_eaten = 0;
		prog->philos[i].write_lock = &prog->write_lock;
		prog->philos[i].meal_lock = &prog->meal_lock;
		prog->philos[i].dead_lock = &prog->dead_lock;
		prog->philos[i].l_fork = &prog->forks[i];
		prog->philos[i].dead = &prog->dead_flag;
		//philos[i].start_time = get_current_time();
		//philos[i].last_meal = get_current_time();
		if (i == 0)
			prog->philos[i].r_fork = &prog->forks[prog->nb_of_philos -1];
		else
			prog->philos[i].r_fork = &prog->forks[i - 1];
		i++;
	}
}

void init_mutex(t_program *program)
{
	size_t i;

	i = 0;
	while (i < program->nb_of_philos)
	{
		pthread_mutex_init(&program->forks[i], NULL);
		i++;
	}
}