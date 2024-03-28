/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:54:05 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/20 12:22:45 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

void	init_args(t_philo_program *prog, char **argv)
{
	prog->nb_philos = ft_atoi(argv[1]);
	prog->time_to_die = ft_atoi(argv[2]);
	prog->time_to_eat = ft_atoi(argv[3]);
	prog->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog->nb_must_eat = ft_atoi(argv[5]);
}

int check_args(t_philo_program *prog, char **argv)
{
	if (check_if_nb(argv[1]) || check_if_nb(argv[2]) || check_if_nb(argv[3])
		|| check_if_nb(argv[4]))
		return(ft_error(1));
	if (ft_atoi(argv[1]) < 2 || ft_atoi(argv[1]) > MAX_PHILOS)
		return (ft_error(2));
	if (ft_atoi(argv[2]) <= 0)
		return(ft_error(3));
	if (ft_atoi(argv[3]) <= 0)
		return(ft_error(4));
	if (ft_atoi(argv[4]) <= 0)
		return(ft_error(5));
	if (argv[5] && (check_if_nb(argv[5]) || ft_atoi(argv[5]) <= 0))
		return(ft_error(6));
	init_args(prog, argv);
	return (0);
}
