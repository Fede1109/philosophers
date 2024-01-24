/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:08 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/01/23 18:26:03 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//TODO: Lock fork (r y L)
//TODO: comé
//TODO: UnLock  (r y l)
//TODO: sobar
//TODO: pensar para lock forrk y comé

void	routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *) ptr;
	while (philo->dead_lock != 1)
	{
		write(1, "philo is waiting", 16);
		if (pthread_mutex_lock(philo->r_fork) == 0 && pthread_mutex_lock(philo->l_fork) == 0)
		{
			write(1, "philo is eating", 16);
			philo->meals_eaten++;
			usleep(philo->time_to_eat);
			philo->last_meal = get_current_time();
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
		}
		if(philo->nb_times_to_eat == philo->meals_eaten)
			philo->dead_lock = 1;
		usleep(philo->time_to_sleep);
	}
}