/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:27:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2024/04/08 11:20:44 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"
// int mails = 0;
// pthread_mutex_t mutex;
// void	*routine()
// {
// 	int i = 0;
// 	//*1
// 	/* printf("Starting\n");
// 	sleep(3);
// 	printf("Finishing\n"); */

// //*2
//     for (int i = 0; i < 10000000; i++) {
//         pthread_mutex_lock(&mutex);
//         mails++;
//         pthread_mutex_unlock(&mutex);
//     }

	
// 	//*3
// /* 	int i;

// 	i = 0;
// 	while (i < 10000000)
// 	{ 
// 		pthread_mutex_lock(&mutex);
// 		mails++;
// 		pthread_mutex_unlock(&mutex);
// 		i++;
// 	}
// */
// 	return (0); 
// }

// int main(void)
// {
// 	//*1
// /* 	pthread_t	t1;
// 	pthread_t	t2;
// 	pthread_t	t3;
// 	pthread_create(&t1, NULL,&routine, NULL);
// 	pthread_create(&t2, NULL,&routine, NULL);
// 	pthread_create(&t3, NULL,&routine, NULL);
// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	pthread_join(t3, NULL); */
// //*2
//  /* 	pthread_t	t1;
// 	pthread_t	t2;
// 	pthread_t	t3;
// 	pthread_t	t4;
// 	pthread_mutex_init(&mutex, NULL);
// 	pthread_create(&t1, NULL,&routine, NULL);
// 	pthread_create(&t2, NULL,&routine, NULL);
// 	pthread_create(&t3, NULL,&routine, NULL);
// 	pthread_create(&t4, NULL,&routine, NULL);
// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	pthread_join(t3, NULL);
// 	pthread_join(t4, NULL);
// 	pthread_mutex_destroy(&mutex);

// 	printf("Numbres of maills: %d\n", mails); */

// 	//*3
// 	int	i;

// 	i = 0;
// 	pthread_t	th[8];
// 	pthread_mutex_init(&mutex, NULL);
// 	for (int i = 0; i < 8; i++)
// 	{
// 		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
// 		{
// 			perror("Failed to create thread");
// 			return (1);
// 		}
// 		printf("Thread %d has started\n", i);
// 	}
// 	for (int i = 0; i < 8; i++)
// 	{
// 		if (pthread_join(th[i],  NULL) != 0)
// 			return (2);
// 		printf("Thread %d has finished execution\n", i);
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("Numbres of maills: %d\n", mails);
// 	return (0);
// }
size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}


int main(void)
{	
	size_t init;
	while (1)
	{
		init = get_current_time();
		ft_usleep(2000);
		printf("mili: %zu\n", get_current_time() - init);
	}	
	return (0);
}
