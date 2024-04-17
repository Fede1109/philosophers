/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:00:01 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/17 12:36:33 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_think(t_philo *philo)
{
	print_msg("is thinking", philo, THINK);
}

void	ph_sleep(t_philo *philo)
{
	print_msg("is sleeping", philo, SLEEP);
	ft_sleep(*philo->time_to_sleep);
}

void	ph_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("took a fork", philo, EAT);
	pthread_mutex_lock(philo->l_fork);
	print_msg("took a fork", philo, EAT);
	print_msg("is eating", philo, EAT);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_sleep(*philo->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
