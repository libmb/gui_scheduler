/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_add_job.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:37:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:40:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_gui_scheduler.h"

#include <stdlib.h>

#include "internal.h"

t_err	mb_gui_scheduler_add_job(
	t_mb_gui_scheduler *self,
	t_mb_gui_scheduler_job job
)
{
	t_mb_gui_scheduler_job_queue_node *const	new_node
		= malloc(sizeof(t_mb_gui_scheduler_job_queue_node));

	if (!new_node)
		return (true);
	new_node->job = job;
	new_node->next = NULL;
	if (self->job_queue_head)
	{
		self->job_queue_head = new_node;
		self->job_queue_tail = new_node;
	}
	else
	{
		self->job_queue_tail->next = new_node;
		self->job_queue_tail = new_node;
	}
	return (false);
}
