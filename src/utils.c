/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:22 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/17 11:10:05 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void ft_error(const char *error)
{
	ft_printf("%s\n", error);
	return (0);
}

void pepe(void *table);
{
	table = (t_table)table;
	pthread_mutex_lock(&table->forks.fork_id);
	//funcion
	pthread_mutex_unlock(&table->forks.fork_id);
}

int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;

	sign = 1;
	result = 0;
	while ((*str == ' ' || ('\t' <= *str && *str <= '\r')))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > LONG_MAX && sign > 0)
			return (-1);
		if (result > LONG_MAX && sign < 0)
			return (0);
		str++;
	}
	return (result * sign);
}