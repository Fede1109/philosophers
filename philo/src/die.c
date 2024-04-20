/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:00:26 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/20 16:18:47 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_all_eaten(t_philo *philos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (*philos->nb_must_eat != -1)
	{
		while (i < *philos->nb_philos)
		{
			pthread_mutex_lock(philos->meal_lock);
			if (*philos->nb_must_eat == philos[i].meals_eaten)
			{
				count++;
				i++;
			}
			pthread_mutex_unlock(philos->meal_lock);
		}
		if (count == *philos->nb_philos)
		{
			pthread_mutex_lock(philos->dead_lock);
			*philos->dead_flag = 1;
			return (pthread_mutex_unlock(philos->dead_lock), 1);
		}
	}
	return (0);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead_flag == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	check_philo_death(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= *philo->time_to_die)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_any_death(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < *philos->nb_philos)
	{
		if (check_philo_death(&philos[i]))
		{
			print_msg("died", &philos[i], DIE);
			pthread_mutex_lock(philos->dead_lock);
			*philos->dead_flag = 1;
			pthread_mutex_unlock(philos->dead_lock);
			return (1);
		}
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
		if (check_any_death(philos) || check_all_eaten(philos))
			break ;
	}
	return (ptr);
}
