/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:21:17 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/17 10:25:06 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void parse_argv(char **argv, t_table *table)
{
	table->philo_nb = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]) * 1e3;
	table->time_eat = ft_atoi(argv[3]) * 1e3;
	table->time_sleep = ft_atoi(argv[4]) * 1e3;
	if (table->time_die < 6e4
		|| table->time_eat < 6e4
		|| table->time_sleep < 6e4)
		ft_error("use times > 60 ms");
	if (argv[5])
		table->limit_meal = ft_atoi(argv[5]);
	else
		table->limit_meal = -1;
	return;
}

void init(t_table *table)
{	
	int i;
	i = 0;
	table->end = false;
	table->philos = safe_malloc(table->philo_nb);
	while (i < table->philo_nb)
	{
		pthread_mutex_init(&table->forks[i].fork, NULL);
		pthread_create(&table->philos[i].thread_id, NULL, &pepe, (void *)table);
		table->philos[i].id = i + 1;
		table->forks[i].fork_id = i + 1;
		i++;
	}
}

void destory(t_table *table)
{
	int i;
	pthread_join(table->forks[i].fork_id, NULL);
	pthread_mutex_destroy(&table->forks->fork); //array de forks
}