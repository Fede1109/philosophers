/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:07:29 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/20 15:23:00 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	leaks(void)
{
	system("leaks -q philo");
}

// atexit(leaks);
int	main(int argc, char **argv)
{
	t_philo_program	program;

	if (argc != 5 && argc != 6)
		return (ft_error(0));
	if (check_args(&program, argv) != 0)
		return (1);
	init_all(&program, argv);
	destroy_mutex(&program);
	return (0);
}
