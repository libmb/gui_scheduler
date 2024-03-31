/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:17:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/30 16:54:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_GUI_SCHEDULER_H
# define MB_GUI_SCHEDULER_H

# include "mb_gui_scheduler_type.h"

# include <stddef.h>

/**
 * @brief initialize scheduler
 *
 * @param thread_count scheduler's thread count, 0 to auto detect
 * @return t_mb_gui_scheduler* opaque pointer
 */
t_mb_gui_scheduler	*mb_gui_scheduler_new(size_t thread_count);

/**
 * @brief user must call this function before entering critical section
 */
t_err				mb_gui_scheduler_lock(t_mb_gui_scheduler *self);

/**
 * @brief user must call this function after leaving critical section
 */
t_err				mb_gui_scheduler_unlock(t_mb_gui_scheduler *self);

/**
 * @brief queue jok
 *
 * @param optional_out used to fine-control queued job (remove, change priority)
 */
t_err				mb_gui_scheduler_add_job(
						t_mb_gui_scheduler *self,
						t_mb_gui_scheduler_job job,
						t_mb_gui_scheduler_controller *optional_out);

t_err				mb_gui_scheduler_job_delete(void *TODO); // TODO: complete

#endif
