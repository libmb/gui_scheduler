/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_get_job.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:09:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:30:54 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

#include <stdlib.h>

/**
 * @brief get job from queue
 *
 * @return true if successfully got job from queue
 * @return false if no job available in queue
 */
static bool	from_queue(t_mb_gui_scheduler *self, t_mb_gui_scheduler_job *out)
{
	t_mb_gui_scheduler_job_queue_node	*next_head;

	if (!self->job_queue_head)
		return (false);
	next_head = self->job_queue_head->next;
	*out = self->job_queue_head->job;
	free(self->job_queue_head);
	self->job_queue_head = next_head;
	if (!next_head)
		self->job_queue_tail = NULL;
	return (true);
}

bool	mb_gui_scheduler_get_job(
	t_mb_gui_scheduler *self,
	t_mb_gui_scheduler_job *out
)
{
	bool	result;

	mb_mutex_lock(self->mutex_get_job);
	if (self->is_stopped)
	{
		mb_mutex_unlock(self->mutex_get_job);
		return (false);
	}
	if (from_queue(self, out))
	{
		mb_mutex_unlock(self->mutex_get_job);
		return (true);
	}
	if ((*self->get_job)(self, self->context))
	{
		mb_mutex_lock(self->mutex_is_error);
		self->is_error = true;
		mb_mutex_unlock(self->mutex_is_error);
		mb_mutex_unlock(self->mutex_get_job);
		return (false);
	}
	result = from_queue(self, out);
	self->is_stopped = !result;
	mb_mutex_unlock(self->mutex_get_job);
	return (result);
}
