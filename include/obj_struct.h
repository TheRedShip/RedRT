/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:41:06 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 18:27:35 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_STRUCT_H
# define OBJ_STRUCT_H

# include "RT.h"

typedef struct
{
	t_vec4	origin;
} Sphere;

typedef struct 
{
	t_vec4	type;
	t_vec4	color;
	t_vec4	mat;
	Sphere	sphere;
} Object;


#endif