/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:22 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/09 15:45:26 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void p_error(const char *error)
{
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

void parse_argv(char **argv, t_table *table)
{
	table->philo_nb = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]) * 1e3;
	table->time_eat = ft_atoi(argv[3]) * 1e3;
	table->time_sleep = ft_atoi(argv[4]) * 1e3;
	if (table->time_die < 6e4
		|| table->time_eat < 6e4
		|| table->time_sleep < 6e4)
		p_error("use times > 60 ms");
	if (argv[5])
		table->limit_meal = ft_atoi(argv[5]);
	else
		table->limit_meal = -1;
	return;
}