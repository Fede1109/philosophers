/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:52:57 by ecortes-          #+#    #+#             */
/*   Updated: 2024/01/17 09:59:01 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *safe_malloc(size_t bytes)
{
	void *ret;

	ret = malloc(bytes);
	if (ret == NULL)
		ft_error("Error in malloc");
	return (ret);
}
//mutex safe
/*
init-destory-lock-unlock
*/
/*
static void handle_mtx_errors(int status, t_code code)
{
	if (status == 0)
		return;
	if (status == EINVAL && (code == LOCK || code == UNLOCK))
		ft_error("the value specified by mutex is invalid\n");
	else if (status == EINVAL && code == INIT)
		ft_error("the value specified by attr is invalid\n");
	else if (status == EDEADLK)
		ft_error("a deadlock would occur if the thread blocked waiting for mutex\n");
	else if (status == EPERM)
		ft_error("the current thread doesnt hold a lock on mutex\n");
	else if (status == ENOMEM)
		ft_error("the process cant allocate enough memory to create another mutex\n");
	else if (status = EBUSY)
		ft_error("Mutex is locked\n");
}

void safe_mutex(t_mtx *mutex, t_code code)
{
	if (code == LOCK)
		handle_mtx_errors(pthread_mutex_lock(mutex), code);
	else if (code == UNLOCK)
		handle_mtx_errors(pthread_mutex_unlock(mutex), code);
	else if (code == INIT)
		handle_mtx_errors(pthread_mutex_init(mutex, NULL), code);
	else if (code == DESTROY)
		handle_mtx_errors(pthread_mutex_destroy(mutex), code);
	else
		ft_error("wrong code for mutex");
}

//threads
static void handle_thrd_errors(int status, t_code code)
{
	if (status == 0)
		return;
	if (status == EAGAIN)
		ft_error("no resources to cretae another thread\n");
	else if (status == EINVAL && code == CREATE)
		ft_error("the value specified by attr is invalid\n");
	else if (status == EINVAL && (code == JOIN || code == DETACH))
		ft_error("the value specified by attr is invalid\n");
	else if (status == EDEADLK)
		ft_error("deadlock detected or vañue thread specifies the calling thread\n");
	else if (status == EPERM)
		ft_error("the caller doesnt have appropiate permision\n");
	else if (status == ESRCH)
		ft_error("no thread found that corresponds to the thrwad id\n");
}
*/