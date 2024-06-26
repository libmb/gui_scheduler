/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_worker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:02:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:05:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_gui_scheduler.h"

#include <stdlib.h>

#include "internal.h"

static bool	is_error(t_mb_gui_scheduler *self)
{
	bool	result;

	mb_mutex_lock(self->mutex_is_error);
	result = self->is_error;
	mb_mutex_unlock(self->mutex_is_error);
	return (result);
}

static void	set_error(t_mb_gui_scheduler *self)
{
	mb_mutex_lock(self->mutex_is_error);
	self->is_error = true;
	mb_mutex_unlock(self->mutex_is_error);
}

void	mb_gui_scheduler_worker(t_mb_gui_scheduler *self)
{
	t_mb_gui_scheduler_job	job;

	while (!is_error(self) && mb_gui_scheduler_get_job(self, &job))
	{
		if ((*job.func)(job.context))
		{
			set_error(self);
			if (job.free_context)
				(*job.free_context)(job.context);
			return ;
		}
		if (job.free_context)
			(*job.free_context)(job.context);
	}
}
