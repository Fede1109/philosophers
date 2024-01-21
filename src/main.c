#include "../include/philo.h"

int	main(int argc, char **argv)
{
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
	init_struct(argv);

	
}