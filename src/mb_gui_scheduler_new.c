/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_new.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:27:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/08 03:09:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_gui_scheduler.h"

#include <stdlib.h>

#include "mb_mutex.h"

#include "internal.h"

#ifdef _WIN32

// TODO: add Windows support
static t_err	platform_dependent_part(t_mb_gui_scheduler *self)
{
}

#else

static void	*dummy_thread_routine_wrapper(void *context)
{
	mb_gui_scheduler_worker(context);
	return (NULL);
}

static t_err	platform_dependent_part(t_mb_gui_scheduler *self)
{
	pthread_t *const	arr = malloc(sizeof(pthread_t) * self->thread_count);
	size_t				i;

	if (!arr)
		return (true);
	self->_.threads = arr;
	i = (size_t)-1;
	while (++i < self->thread_count)
		if (pthread_create(&arr[i], NULL, dummy_thread_routine_wrapper, self))
			break ;
	if (i == self->thread_count)
		return (false);
	while (--i != (size_t)(-1))
		pthread_join(arr[i], NULL);
	return (true);
}

#endif

t_mb_gui_scheduler	*mb_gui_scheduler_new(
	size_t thread_count,
	void *context,
	t_mb_gui_scheduler_get_job get_job
)
{
	t_mb_gui_scheduler *const	result = malloc(sizeof(t_mb_gui_scheduler));

	if (!thread_count && mb_gui_scheduler_detect_cpu_count(&thread_count))
	{
		free(result);
		return (NULL);
	}
	result->thread_count = thread_count;
	result->context = context;
	result->get_job = get_job;
	result->job_queue_head = NULL;
	result->job_queue_tail = NULL;
	if (mb_mutex_init(&result->mutex_job_queue))
	{
		free(result);
		return (NULL);
	}
	if (platform_dependent_part(result))
	{
		mb_mutex_destroy(result->mutex_job_queue);
		free(result);
		return (NULL);
	}
	return (result);
}
