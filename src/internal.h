/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:13:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/09 01:51:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "mb_gui_scheduler.h"

# include <stddef.h>

# include "mb_mutex.h"

# ifdef _WIN32
// TODO: add Windows support
# else
#  include <pthread.h>
# endif

# ifdef _WIN32

// TODO: add Windows support
typedef struct s_mb_gui_scheduler_platform_dependent_part
{
}	t_mb_gui_scheduler_platform_dependent_part;

# else

typedef struct s_mb_gui_scheduler_platform_dependent_part
{
	pthread_t	*threads;
}	t_mb_gui_scheduler_platform_dependent_part;

# endif

typedef struct s_mb_gui_scheduler_job_queue_node
{
	struct s_mb_gui_scheduler_job_queue_node	*next;
	t_mb_gui_scheduler_job						job;
}	t_mb_gui_scheduler_job_queue_node;

struct s_mb_gui_scheduler
{
	size_t										thread_count;
	void										*context;
	t_mb_gui_scheduler_get_job					get_job;
	t_mb_gui_scheduler_job_queue_node			*job_queue_head;
	t_mb_gui_scheduler_job_queue_node			*job_queue_tail;
	t_mb_mutex									*mutex_is_error;
	t_mb_mutex									*mutex_get_job;
	bool										is_error;
	bool										is_stopped;
	char										_padding[
		sizeof(void *) - (sizeof(bool) * 2)];
	t_mb_gui_scheduler_platform_dependent_part	_;
};

t_err	mb_gui_scheduler_detect_cpu_count(size_t *out);
t_err	mb_gui_scheduler_new_internal(t_mb_gui_scheduler *self);
void	mb_gui_scheduler_new_internal_delete(t_mb_gui_scheduler *self);
void	mb_gui_scheduler_worker(t_mb_gui_scheduler *self);

bool	mb_gui_scheduler_get_job(
			t_mb_gui_scheduler *self,
			t_mb_gui_scheduler_job *out);

#endif
