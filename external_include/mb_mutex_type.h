/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_mutex_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:14:51 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/08 02:52:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_MUTEX_TYPE_H
# define MB_MUTEX_TYPE_H

# include <stdbool.h>

# ifndef MB_ERR_DEFINED
#  define MB_ERR_DEFINED

typedef bool				t_mb_err;

# endif

typedef struct s_mb_mutex	t_mb_mutex;

#endif
