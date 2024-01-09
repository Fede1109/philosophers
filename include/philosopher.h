/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:32 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/09 15:45:03 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft.h"

//./philo 5 800 200 200 [5]

typedef pthread_mutex_t t_mtx;
typedef struct s_fork t_table;


typedef struct s_fork
{
	t_mtx fork;
	int fork_id;
}	t_fork;

typedef struct s_ph
{
	int id;
	long meals;
	bool full;
	long meal_time;
	t_fork *right_fk;
	t_fork *left_fk;
	pthread_t thread_id;
}	t_philo;

typedef struct s_table
{
	long philo_nb;
	long time_die;
	long time_eat;
	long time_sleep;
	long nb_meals;
	long limit_meal;
	long time_start;
	t_fork *forks;
	t_philo *philos;
}	t_table;

//prototypes
void p_error(const char *error);
void parse_argv(char **argv, t_table *table);
# endif