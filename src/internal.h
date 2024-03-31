/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:13:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/30 16:25:02 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "mb_gui_scheduler_type.h"

# include <stddef.h>

# ifdef _WIN32
// TODO: add Windows support
# else
#  include <pthread.h>
# endif

# ifdef _WIN32

// TODO: add Windows support
struct s_mb_gui_scheduler
{
};

# else

struct s_mb_gui_scheduler
{
	size_t			thread_count;
	pthread_t		*threads;
	pthread_mutex_t	mutex;
};

# endif

t_err	mb_gui_scheduler_detect_cpu_count(size_t *out);

#endif
