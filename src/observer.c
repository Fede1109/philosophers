/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:18:20 by ecortes-          #+#    #+#             */
/*   Updated: 2024/02/13 15:32:17 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *observer(void *ptr)
{
	t_program *program;
	
	program = (t_program *)ptr;
	while(1)
	{
		if(program->dead_flag == 1)
		{
			pthread_mutex_lock(&program->write_lock);
			break;
		}
	}
	return (NULL);
}