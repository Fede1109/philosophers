/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:07:29 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/17 17:21:25 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
void	leaks()
{
	system("leaks -q philo");
}
int	main(int argc, char **argv)
{
	t_philo_program	program;

	atexit(leaks);
	if (argc != 5 && argc != 6)
		return (ft_error(0));
	if (check_args(&program, argv) != 0)
		return (1);
	init_all(&program, argv);
	destroy_mutex(&program);
	return (0);
}
