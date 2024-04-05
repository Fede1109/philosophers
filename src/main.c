/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:07:29 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/05 17:00:41 by fdiaz-gu         ###   ########.fr       */
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
	return (0);
}