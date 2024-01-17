/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:58:32 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/17 11:08:14 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILo_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

//enum para mutex y thread
/*
typedef enum e_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_code;
*/
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
	bool end;
	t_fork *forks;
	t_philo *philos;
}	t_table;

//prototypes
void ft_error(const char *error);
void parse_argv(char **argv, t_table *table);
void *safe_malloc(size_t bytes);
void pepe(t_table *table);
# endif