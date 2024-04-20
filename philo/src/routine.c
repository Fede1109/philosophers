/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:02:07 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/20 16:19:45 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_routine(t_philo_program *prog, int philos)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	if (pthread_create(&monitor, NULL, &monitoring, prog->philos) != 0)
		return ;
	while (i < philos)
	{
		if (pthread_create(&prog->philos[i].thread, NULL,
				&routine, &prog->philos[i]) != 0)
			destroy_mutex(prog);
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		destroy_mutex(prog);
	while (i < philos)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			destroy_mutex(prog);
		i++;
	}
	return ;
}

void	*routine(void	*pointer)
{
	t_philo	*philo;

	philo = (t_philo *) pointer;
	if (philo->id % 2 == 0)
		ft_sleep(1);
	while (!dead_loop(philo))
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (pointer);
}
