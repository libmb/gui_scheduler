/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:17:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/08 02:50:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_GUI_SCHEDULER_H
# define MB_GUI_SCHEDULER_H

# include "mb_gui_scheduler_type.h"

# include <stddef.h>

typedef struct s_mb_gui_scheduler_mutex	t_mb_gui_scheduler_mutex;

typedef t_err							(*t_mb_gui_scheduler_get_job)(
											t_mb_gui_scheduler *self,
											void *context);

/**
 * @brief initialize scheduler
 *
 * @param thread_count scheduler's thread count, 0 to auto detect
 * @param context user pointer for get_job callback
 * @param get_job callback to take job called when job queue is empty
 * @return t_mb_gui_scheduler* opaque pointer
 */
t_mb_gui_scheduler	*mb_gui_scheduler_new(
						size_t thread_count,
						void *context,
						t_mb_gui_scheduler_get_job get_job);

/**
 * @brief queue job. this must be called only in get_job callback
 */
t_err				mb_gui_scheduler_add_job(
						t_mb_gui_scheduler *self,
						t_mb_gui_scheduler_job job);

/**
 * @brief clear job queue, and force the scheduler to call get_job callback
 */
t_err				mb_gui_scheduler_clear_job(t_mb_gui_scheduler *self);

/**
 * @brief stop worker, wait for it to finish
 */
t_err				mb_gui_scheduler_stop_join(t_mb_gui_scheduler *self);

/**
 * @brief stop worker, not wait for it to finish
 */
t_err				mb_gui_scheduler_stop_detach(t_mb_gui_scheduler *self);

/**
 * @brief stop worker if not stopped (default join), and delete scheduler
 */
void				mb_gui_scheduler_delete(t_mb_gui_scheduler *self);

/**
 * @brief check if workers are stopped because of error
 */
bool				mb_gui_scheduler_has_error(t_mb_gui_scheduler *self);

#endif
