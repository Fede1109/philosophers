/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:54:05 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/08 12:40:19 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

void	init_args(t_philo *philo, char **argv)
{
	philo->nb_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->nb_must_eat = ft_atoi(argv[5]);
	else
		philo->nb_must_eat = -1;
}

int check_args(t_philo_program *prog, char **argv)
{
	(void) prog;
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
	create_philos(prog, ft_atoi(argv[1]));
	return (0);
}
