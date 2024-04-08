/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_new_internal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:58:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:16:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

t_err	mb_gui_scheduler_new_internal(t_mb_gui_scheduler *self)
{
	if (mb_mutex_init(&self->mutex_is_error))
		return (true);
	if (mb_mutex_init(&self->mutex_get_job))
	{
		mb_mutex_destroy(self->mutex_is_error);
		return (true);
	}
	return (false);
}
