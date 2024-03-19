/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:07:29 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/19 14:41:27 by fdiaz-gu         ###   ########.fr       */
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
	printf("philos: %d\n", program.nb_philos);
	printf("tm die: %d\n", program.time_to_die);
	printf("tm eat: %d\n", program.time_to_eat);
	printf("tm sleep: %d\n", program.time_to_sleep);
	printf("nb must eat: %d\n", program.nb_must_eat);

	return (0);
}