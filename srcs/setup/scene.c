/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:04:41 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 20:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

void	init_scene(Scene *scene)
{
	Sphere sphere[objNum] = {{ {-1.0f, 1.0f, -3.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 0.0f}, {0.0,1,0,0} },
				{ {0.0f, 0.0f, -3.0f, 0.3f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0,0,0,0} },
				{ {0.0f, -1.5f, -3.0f, 1.0f}, {1.0f, 0.0f, 0.0f, 0.0f}, {0.0,0,0,0} }};

	for (int i = 0; i < objNum; i++)
		scene->obj[i] = sphere[i];

	scene->camera.origin = (t_vec4){0.0f, 0.0f, 0.0f};
}