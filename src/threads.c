/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:00:28 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/18 20:44:39 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void threads(t_program *program)
{
	pthread_t obs;
	size_t i;
	
	i = 0;
	if(!pthread_create(&obs, NULL, &func, program->philos))
		free_destroy(program);
	while(i < program->nb_of_philos)
	{
		if(!pthread_create(&program->philos[i], NULL, &routine, &program))
			free_destroy(program);
		i++;
	}
	if (!pthread_join(obs, NULL))
		free_destroy(program);
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
	
}
