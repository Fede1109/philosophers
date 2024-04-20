/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:08:23 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/20 10:31:42 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(char *str, t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->print_lock);
	if (!dead_loop(philo))
	{
		printf("%s%zu %d ", action,
			get_current_time() - philo->start_time, philo->id);
		printf("%s%s\n", str, RESET);
	}
	pthread_mutex_unlock(philo->print_lock);
}

int	ft_error(int nb)
{
	if (nb == 0)
		printf("%s Invalid number of arguments %s\n", RED, RESET);
	else if (nb == 1)
		printf("%s Invalid argument, only numbers %s\n", RED, RESET);
	else if (nb == 2)
		printf("%s Number of philos between 2 & 200 %s\n", RED, RESET);
	else if (nb == 3)
		printf("%s Invalid time to die %s\n", RED, RESET);
	else if (nb == 4)
		printf("%s Invalid time to eat %s\n", RED, RESET);
	else if (nb == 5)
		printf("%s Invalid time to sleep %s\n", RED, RESET);
	else if (nb == 6)
		printf("%s Invalid times to eat %s\n", RED, RESET);
	return (1);
}

int	check_if_nb(char *str)
{
	int	i;	

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
		return (1);
	return (0);
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
