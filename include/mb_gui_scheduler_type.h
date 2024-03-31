/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_type.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:07:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/30 16:46:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_GUI_SCHEDULER_TYPE_H
# define MB_GUI_SCHEDULER_TYPE_H

# include <stddef.h>
# include <stdbool.h>

typedef bool									t_err;

typedef struct s_mb_gui_scheduler				t_mb_gui_scheduler;

typedef void									*(*t_mb_gui_scheduler_job_func)(
													void *context);

typedef struct s_mb_gui_scheduler_job
{
	t_mb_gui_scheduler_job_func	func;
	void						*context;
	size_t						priority;
}	t_mb_gui_scheduler_job;

typedef struct s_mb_gui_scheduler_controller	t_mb_gui_scheduler_controller;

#endif
