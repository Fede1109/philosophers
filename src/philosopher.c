/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:26 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/09 15:31:45 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

// ./philo 5 800 200 200 [5]
int main(int argc, char **argv)
{
	t_table table;
	if (argc == 5 || argc == 6)
	{
		parse_argvs(argv, &table);
		init(&table);
	}
	else
		p_error("Wrong input\n prototype : ./philo 5 800 200 200 [5]\n");
	

	return (0);
}