/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:00:01 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/16 15:53:37 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_think(t_philo *philo)
{
	print_msg("is thinking", philo);
}

void	ph_sleep(t_philo *philo)
{
	print_msg("is sleeping", philo);
	ft_sleep(*philo->time_to_sleep);
}

void	ph_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("took a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	print_msg("took a fork", philo);
	if (get_current_time() - philo->last_meal > *philo->time_to_die)
		*philo->dead_flag = 1;
	print_msg("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_sleep(*philo->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
