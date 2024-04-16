/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:14:52 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/16 16:16:56 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_mutex(t_philo_program *prog)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->print_lock);
	pthread_mutex_destroy(&prog->dead_lock);
	while (i < prog->nb_philos)
	{
		pthread_mutex_destroy(&prog->forks[i]);
		i++;
	}
}
