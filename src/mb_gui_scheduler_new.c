/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_gui_scheduler_new.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:27:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/30 16:32:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "mb_gui_scheduler.h"

t_mb_gui_scheduler	*mb_gui_scheduler_new(size_t thread_count)
{
	if (!thread_count && mb_gui_scheduler_detect_cpu_count(&thread_count))
		return (NULL);
	(void)"// TODO: implement this";
	return (NULL);
}
