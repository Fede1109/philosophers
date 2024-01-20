/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:02:01 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/17 20:14:25 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_program program;
	t_philo *philos;
	t_mutex *forks;


	if (argc != 5 ||argc != 6)
		return (1);
	parse_argv(argv);
	init(&program, argv);
	threads();
}

void free_destroy(t_program *program)
{
	size_t i;
	
	i = 0;
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	while(i < program->nb_of_philos)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	free(program->philos);
	free(program->forks);
}