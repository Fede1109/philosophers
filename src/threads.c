/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:00:28 by ecortes-          #+#    #+#             */
/*   Updated: 2024/02/13 15:36:13 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void threads(t_program *program)
{
	pthread_t obs;
	size_t i;
	i = 0;
	if(!pthread_create(&obs, NULL, &observer, (void *)program))
		free_destroy(program);
	while(i < program->nb_of_philos)
	{
		if(pthread_create(&(program->philos[i].thread), NULL, &routine, (void *)(&program->philos[i])) != 0)
		{
			if (program)
				free_destroy(program);
		}
		i++;
	}
	i = 0;
	while (i < program->nb_of_philos)
	{
		if(!pthread_join(program->philos[i].thread, NULL))
			free_destroy(program);
		i++;
	}
	if (!pthread_join(obs, NULL))
		free_destroy(program);
}

void	*routine(void *ptr)
{
	t_philo	*philo;
	
	philo = (t_philo *) ptr;
	while (*philo->dead != 1)
	{
		eat(philo);
		think(philo);
		philosleep(philo);
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	time = get_current_time() - philo->start_time;
	if(time > *philo->time_to_die)
		*philo->dead = 1;
	else
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%zu %d is eating\n", time, philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
	philo->meals_eaten++;
	ft_usleep(*philo->time_to_eat);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);

	if(*philo->max_meals == philo->meals_eaten)
		*philo->dead = 1;
}

void	think(t_philo *philo)
{
	size_t	time;

	time = get_current_time() - philo->start_time;
	if(time > *philo->time_to_die)
		*philo->dead = 1;
	else
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%zu %d is thinking\n", time, philo->id);
		pthread_mutex_unlock(philo->write_lock);
	}
}

void philosleep(t_philo *philo)
{
	size_t time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if(time > *philo->time_to_die)
		*philo->dead = 1;
	else
		printf("%zu %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	ft_usleep(*philo->time_to_sleep);
}
