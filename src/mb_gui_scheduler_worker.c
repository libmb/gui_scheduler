/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_worker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:02:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/08 02:09:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_gui_scheduler.h"

#include <stdlib.h>

#include "internal.h"

void	mb_gui_scheduler_worker(t_mb_gui_scheduler *self)
{
	t_mb_gui_scheduler_job	job;

	while (!platform_dependent_part_check_if_error(self)
		&& mb_gui_scheduler_get_job(self, &job))
	{
		if ((*job.func)(job.context))
		{
			platform_dependent_part_mark_as_error(self);
			return ;
		}
	}
}
