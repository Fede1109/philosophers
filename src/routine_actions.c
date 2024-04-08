/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:00:01 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/08 16:22:36 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void	think(t_philo *philo)
{
	printf("Philo %d is thinking", philo->id);
}

void	sleep(t_philo *philo)
{
	printf("Philo %d is sleeping", philo->id);
	//TODO: sleeping function
	sleeping(philo->time_to_sleep);
	
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	printf("Philo %d took left fork", philo->id);
	pthread_mutex_lock(&philo->r_fork);
	printf("Philo %d took a fork", philo->id);
	printf("Philo %d is eating", philo->id);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}