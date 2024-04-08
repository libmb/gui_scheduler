/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_has_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:49:36 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:50:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_gui_scheduler.h"

#include "internal.h"

bool	mb_gui_scheduler_has_error(t_mb_gui_scheduler *self)
{
	bool	result;

	mb_mutex_lock(self->mutex_is_error);
	result = self->is_error;
	mb_mutex_unlock(self->mutex_is_error);
	return (result);
}
