/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:41:06 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 14:41:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_STRUCT_H
# define OBJ_STRUCT_H

# include "RT.h"

typedef struct {
	vec4	origin;
	vec4	color;
	vec4	mat;
} Sphere;


#endif