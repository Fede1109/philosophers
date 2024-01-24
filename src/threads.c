/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:00:28 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/24 12:34:21 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void threads(t_program *program)
{
	//pthread_t obs;
	size_t i;
	
	i = 0;
	//if(!pthread_create(&obs, NULL, &func, program->philos))
	//	free_destroy(program);
	while(i < program->nb_of_philos)
	{
		if(!pthread_create(&program->philos[i], NULL, &routine, &program))
			free_destroy(program);
		i++;
	}
	//if (!pthread_join(obs, NULL))
	//	free_destroy(program);
	i = 0;
	while (i < program->nb_of_philos)
	{
		if(!pthread_join(program->philos[i].thread, NULL))
			free_destroy(program);
		i++;
	}
}

void routine(void *ptr)
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
		if(philo->max_meals == philo->meals_eaten)
			philo->dead_lock = 1;
		usleep(philo->time_to_sleep);
	}
}
