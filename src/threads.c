/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:00:28 by ecortes-          #+#    #+#             */
/*   Updated: 2024/02/12 17:06:52 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void *routine(void *ptr);

void threads(t_program *program)
{
	//pthread_t obs;
	size_t i;
	i = 0;
	//if(!pthread_create(&obs, NULL, &func, program->philos))
	//	free_destroy(program);
	while(i < program->nb_of_philos)
	{
		if(pthread_create(&(program->philos[i].thread), NULL, &routine, (void *)(&program->philos[i])) != 0)
		{
			if (program)
				free_destroy(program);
		}
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

void *routine(void *ptr)
{
	t_philo *philo;
	
	philo = (t_philo *) ptr;
	while (*philo->dead != 1)
	// while(1)
	{
		eat(philo);
		think(philo);
		philosleep(philo);
	}
	return (NULL);
}

void eat(t_philo *philo)
{
	char num;

	num = philo->id + 48;
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->write_lock);
	//write timestamp
	write(1, &num, 1);
	write(1, " is eating\n", 12);
	pthread_mutex_unlock(philo->write_lock);
	philo->meals_eaten++;
	usleep(*philo->time_to_eat);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);

	if(*philo->max_meals == philo->meals_eaten)
		*philo->dead = 1;
}

void think(t_philo *philo)
{
	char num;

	num = philo->id + 48;
	if (pthread_mutex_lock(philo->write_lock) == 0)
	{
		write(1, &num, 1);
		write(1, " is thinking\n", 14);
	}
	pthread_mutex_unlock(philo->write_lock);
}

void philosleep(t_philo *philo)
{
	char num;

	num = philo->id + 48;
	pthread_mutex_lock(philo->write_lock);
	write(1, &num, 1);
	write(1, " is sleeping\n", 14);
	pthread_mutex_unlock(philo->write_lock);
	usleep(*philo->time_to_sleep);
}
