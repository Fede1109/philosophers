/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:41 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/23 18:25:05 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void init(t_program *program, char **argv)
{
	program->dead_flag = 0;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->r_fork, NULL);
	pthread_mutex_init(&program->l_fork, NULL);
	init_argv(program, argv[1]);
	init_philos(program);
	init_mutex(program);
}

void init_philos(t_program *prog)
{
	int i;

	i = 0;
	while (i < prog->num_of_philos)
	{
		prog->philos[i].id = ++i;
		prog->philos[i].meals_eaten = 0;
		prog->philos[i].time_to_die = &prog->time_to_die;
		prog->philos[i].time_to_eat = &prog->time_to_eat;
		prog->philos[i].time_to_sleep = &prog->time_to_sleep;
		prog->philos[i].write_lock = &prog->write_lock;
		prog->philos[i].meal_lock = &prog->meal_lock;
		prog->philos[i].dead_lock = &prog->dead_lock;
		prog->philos[i].l_fork = &prog->forks[i];
		// prog->philos[i].dead = &prog->dead_flag;
		prog->philos[i].start_time = get_current_time();
		prog->philos[i].last_meal = get_current_time();
		if (i == 0)
			prog->philos[i].r_fork = &prog->forks[*prog->philos[i].num_of_philos - 1];
		else
			prog->philos[i].r_fork = &prog->forks[i - 1];
		i++;
	}
}
