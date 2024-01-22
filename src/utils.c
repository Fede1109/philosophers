#include "../include/philo.h"

int	init_struct(t_philo *philo, char **str)
{
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->num_of_philos = str[1];
	philo->time_to_die = str[2];
	philo->time_to_eat = str[3];
	philo->time_to_sleep = str[4];
	if (str[5])
		philo->nb_times_to_eat;
	return (1);
}

int ft_check_args(char *str, int i)
{
    if (!check_if_nb(str))
        return (0);
    if (i == 1 && (ft_atoi(str) > 200))
    {
        printf("No more than 200 philosophers.\n");
        return (0);
    }
    if (ft_atoi(str) < 0)
    {
        printf("Wrong number.\n");
        return (0);
    }
    return (1);
}

int	ft_atoi(char *str)
{
	int				sign;
	unsigned long	result;

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

int	check_if_nb(char *str)
{
	int	i;	

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
        return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
        return (0);
	return (1);
}
