/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:48:22 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 01:48:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include "RT.h"

typedef struct s_camera
{
	t_vec4	origin;
	t_vec4	direction;
	mat4	rotation_matrix_x;
	mat4	rotation_matrix_y;
}	Camera;

#endif