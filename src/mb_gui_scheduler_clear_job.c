/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_clear_job.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:40:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:43:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_gui_scheduler.h"

#include <stdlib.h>

#include "internal.h"

void	mb_gui_scheduler_clear_job(t_mb_gui_scheduler *self)
{
	t_mb_gui_scheduler_job_queue_node	*to_remove;

	mb_mutex_lock(self->mutex_get_job);
	while (self->job_queue_head)
	{
		to_remove = self->job_queue_head;
		self->job_queue_head = to_remove->next;
		(*to_remove->job.free_context)(to_remove->job.context);
		free(to_remove);
	}
	self->job_queue_tail = NULL;
	mb_mutex_unlock(self->mutex_get_job);
}
