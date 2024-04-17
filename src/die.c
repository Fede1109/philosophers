/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:00:26 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/17 11:12:40 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead_flag == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	check_philo_death(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	printf("ID: %d - time_to_die: %zu - last_meal: %zu  current_day: %zu - RESTA: %zu\n",
		philo->id, *philo->time_to_die, philo->last_meal, get_current_time(), (get_current_time()- philo->last_meal));
	if (get_current_time() - philo->last_meal > *philo->time_to_die)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_any_death(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < *philos->nb_philos)
	{
		if (*philos[i].dead_flag == 1)
			return (1);
		// if (check_philo_death(&philos[i]))
		// {
		// 	print_msg("died", &philos[i], DIE);
		// 	pthread_mutex_lock(philos->dead_lock);
		// 	*philos->dead_flag = 1;
		// 	pthread_mutex_unlock(philos->dead_lock);
		// 	return (1);
		// }
		i++;
	}
	return (0);
}

void	*monitoring(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *) ptr;
	while (1)
	{
		if (check_any_death(philos))
			break ;
	}
	return (ptr);
}
