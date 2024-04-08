/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_type.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:07:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 00:53:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_GUI_SCHEDULER_TYPE_H
# define MB_GUI_SCHEDULER_TYPE_H

# include <stddef.h>
# include <stdbool.h>

typedef bool						t_err;

typedef struct s_mb_gui_scheduler	t_mb_gui_scheduler;

typedef t_err						(*t_mb_gui_scheduler_job_func)(
										void *context);

typedef struct s_mb_gui_scheduler_job
{
	t_mb_gui_scheduler_job_func	func;
	void						*context;
	void						(*free_context)(void *context);
}	t_mb_gui_scheduler_job;

#endif
