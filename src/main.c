/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:07:29 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/08 12:34:34 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main (int argc, char **argv)
{
	t_philo_program	program;

	if (argc != 5 && argc != 6)
		return (ft_error(0));
	if (check_args(&program, argv) != 0)
		return (1);
	init_all(&program, argv);
	int i = 0;
	while (i < 5)
	{
		printf("NUM: %d\n", program.philos[i].time_to_die);
		i++;
	}
	
	return (0);
}