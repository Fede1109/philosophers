/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:33:45 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/05 16:52:17 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
void	init_philos(t_philo_program *program)
{
	int		i;

	i = 0;
	while (i < program->philos->nb_philos)
	{
		program->philos[i].id = i + 1;
		program->philos[i].last_meal = 0;
		program->philos[i].meals_eaten = 0;
		// program->philos[i].start_time = get_time();
		i++;
	}
	i = 0;
	while (i < program->philos->nb_philos)
	{
		pthread_create(&(program->philos[i].thread), NULL, &routine, NULL);
		i++;
	}
}

void	create_philos(t_philo_program *program, int philos)
{
	program->philos = malloc(sizeof(t_philo) * philos);
	if (!program->philos)
		return ;
}

	