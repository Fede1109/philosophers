/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:07:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/03/19 14:37:56 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>

# define RED "\033[31m"
# define NORMAL "\033[0m"

# define MAX_PHILOS 200

typedef struct s_philo_program
{
	int nb_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_must_eat;
	
}	t_philo_program;



int		ft_atoi(const char *str);
int		check_args(t_philo_program *prog, char **argv);
int		check_if_nb(char *str);
int		ft_error(int nb);
void	init_args(t_philo_program *prog, char **argv);



# endif