/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:26 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/17 10:25:45 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// ./philo 5 800 200 200 [5]
int main(int argc, char **argv)
{
	t_table table;
	struct timeval t_time;

	if (argc == 5 || argc == 6)
	{
		parse_argvs(argv, &table);
		table.time_start = gettimeofday(&t_time, NULL);
		init(&table);
	}
	else
		ft_error("Wrong input\n prototype : ./philo 5 800 200 200 [5]\n");
	return (0);
}
