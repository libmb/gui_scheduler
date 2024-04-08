/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_new_internal_delete.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:58:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:23:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	mb_gui_scheduler_new_internal_delete(t_mb_gui_scheduler *self)
{
	mb_mutex_destroy(self->mutex_is_error);
	mb_mutex_destroy(self->mutex_get_job);
}
