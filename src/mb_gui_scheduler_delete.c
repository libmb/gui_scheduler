/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_delete.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:43:53 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:49:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_gui_scheduler.h"

#include <stdlib.h>

#include "internal.h"

#ifdef _WIN32
# include <windows.h>
#else
# include <pthread.h>
#endif

#ifdef _WIN32

// TODO: add Windows support
static void	platform_dependent_part(t_mb_gui_scheduler *self)
{
}

#else

static void	platform_dependent_part(t_mb_gui_scheduler *self)
{
	size_t	i;

	i = (size_t)-1;
	while (++i < self->thread_count)
		pthread_join(self->_.threads[i], NULL);
	free(self->_.threads);
}

#endif

void	mb_gui_scheduler_delete(t_mb_gui_scheduler *self)
{
	platform_dependent_part(self);
	mb_gui_scheduler_clear_job(self);
	mb_gui_scheduler_new_internal_delete(self);
	free(self);
}
