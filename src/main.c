#include "../include/philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	main(int argc, char **argv)
{
	(void) argv;
	(void) argc;
	int		i;
	t_philo *philo;

	i = 1;
	if (argc != 5 || argc != 6)
	{
		printf("Invalid number of arguments!\n");
		return (0);
	}
	while (argv[i])
	{
		if (!ft_check_args(argv[i], i))
		{
			printf("Invalid argument, only numbers.\n");
			return (0);
		}
		i++;
	}
	
	init_struct(philo, argv);
	
}
