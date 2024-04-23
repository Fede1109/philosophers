/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:33:45 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/23 17:42:38 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philos_args(t_philo_program *prog, t_philo *philo)
{
	philo->meal_lock = &prog->meal_lock;
	philo->print_lock = &prog->print_lock;
	philo->dead_lock = &prog->dead_lock;
	philo->nb_must_eat = &prog->nb_must_eat;
	philo->nb_philos = &prog->nb_philos;
	philo->dead_flag = &prog->dead_flag;
	philo->time_to_die = &prog->time_to_die;
	philo->time_to_eat = &prog->time_to_eat;
	philo->time_to_sleep = &prog->time_to_sleep;
}

void	init_all(t_philo_program *prog, char **argv)
{
	init_forks(prog, ft_atoi(argv[1]));
	init_philos(prog, argv);
}

void	init_forks(t_philo_program *prog, int philos)
{
	int	i;

	i = 0;
	prog->forks = malloc(sizeof(pthread_mutex_t) * philos);
	if (!prog->forks)
		return ;
	while (i < philos)
	{
		if (pthread_mutex_init(&(prog->forks[i]), NULL) != 0)
			destroy_mutex(prog);
		i++;
	}
}

void	init_philos(t_philo_program *prog, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		prog->philos[i].id = i + 1;
		prog->philos[i].meals_eaten = 0;
		init_philos_args(prog, &prog->philos[i]);
		prog->philos[i].last_meal = get_current_time();
		prog->philos[i].start_time = get_current_time();
		prog->philos[i].l_fork = &prog->forks[i];
		if (i == 0)
			prog->philos[i].r_fork = &prog->forks[prog->nb_philos - 1];
		else
			prog->philos[i].r_fork = &prog->forks[i - 1];
		i++;
	}
	prog->dead_flag = 0;
	if (pthread_mutex_init(&prog->print_lock, NULL)
		|| pthread_mutex_init(&prog->dead_lock, NULL)
		|| pthread_mutex_init(&prog->meal_lock, NULL))
		destroy_mutex(prog);
	start_routine(prog, ft_atoi(argv[1]));
}

void	create_philos(t_philo_program *prog, int philos)
{
	prog->philos = malloc(sizeof(t_philo) * philos);
	if (!prog->philos)
		return ;
}
