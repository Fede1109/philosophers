/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:33:45 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/08 12:50:07 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_all(t_philo_program *prog, char **argv)
{
	init_philos(prog, argv);
	// init_forks(prog);
}

void	init_forks(t_philo_program *program)
{
	int	i;

	i = 0;
	program->forks = malloc(sizeof(pthread_mutex_t) * program->philos->nb_philos);
	if (!program->forks)
		return ;
	while (i < program->philos->nb_philos)
	{
		pthread_mutex_init(&(program->forks[i]),  NULL);
		i++;
	}
}
void	init_philos(t_philo_program *program, char **argv)
{
	int		i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		program->philos[i].id = i + 1;
		program->philos[i].last_meal = 0;
		program->philos[i].meals_eaten = 0;
		init_args(&program->philos[i], argv);
		// program->philos[i].start_time = get_time();
		i++;
	}
}
void	create_philos(t_philo_program *program, int philos)
{
	program->philos = malloc(sizeof(t_philo) * philos);
	if (!program->philos)
		return ;
}

	