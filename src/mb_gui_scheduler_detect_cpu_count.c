/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_detect_cpu_count.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:24:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/30 16:24:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

#ifdef _WIN32
# include <windows.h>
#else
# include <unistd.h>
#endif

#ifdef _WIN32

t_err	mb_gui_scheduler_detect_cpu_count(size_t *out)
{
	SYSTEM_INFO	system_into;

	GetSystemInfo(&system_into);
	*out = system_into.dwNumberOfProcessors;
	return (false);
}

#elif defined(_SC_NPROCESSORS_ONLN)

t_err	mb_gui_scheduler_detect_cpu_count(size_t *out)
{
	const long	cpu_count = sysconf(_SC_NPROCESSORS_ONLN);

	if (cpu_count < 0)
		return (true);
	*out = (size_t)cpu_count;
	return (false);
}

#else

t_err	mb_gui_scheduler_detect_cpu_count(size_t *out)
{
	(void)out;
	return (true);
}

#endif
