/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_mutex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:14:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/08 03:03:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_MUTEX_H
# define MB_MUTEX_H

# include "mb_mutex_type.h"

t_mb_err	mb_mutex_init(t_mb_mutex **out);
void		mb_mutex_destroy(t_mb_mutex *self);
void		mb_mutex_lock(t_mb_mutex *self);
void		mb_mutex_unlock(t_mb_mutex *self);

#endif
