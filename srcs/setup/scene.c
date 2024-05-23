/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:04:41 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 19:00:20 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

void	init_scene(Scene *scene)
{
	scene->obj[0].type = (t_vec4){1.0f, 0.0f, 0.0f, 0.0f};
	scene->obj[0].sphere.origin = (t_vec4){75.0f, 25.0f, 0.0f, 60.0f};
	scene->obj[0].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	scene->obj[0].mat = (t_vec4){0.0, 1, 0, 0};

	scene->obj[1].type = (t_vec4){1.0f, 0.0f, 0.0f, 0.0f};
	scene->obj[1].sphere.origin = (t_vec4){0.0f, 2.80f, -3.0f, 1.0f};
	scene->obj[1].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	scene->obj[1].mat = (t_vec4){1.0f, 0, 0, 0};

	scene->obj[2].type = (t_vec4){1.0f, 0.0f, 0.0f, 0.0f};
	scene->obj[2].sphere.origin = (t_vec4){0.8f, 0.35f, -2.3f, 0.5f};
	scene->obj[2].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	scene->obj[2].mat = (t_vec4){0, 0, 0, 0};

	scene->obj[3].type = (t_vec4){1.0f, 0.0f, 0.0f, 0.0f};
	scene->obj[3].sphere.origin = (t_vec4){0.0f, 0.70f, -1.0f, 0.75f};
	scene->obj[3].color = (t_vec4){0.2f, 1.0f, 0.2f, 0.0f};
	scene->obj[3].mat = (t_vec4){0, 0, 0, 0};

	scene->obj[4].type = (t_vec4){1.0f, 0.0f, 0.0f, 0.0f};
	scene->obj[4].sphere.origin = (t_vec4){-0.9f, 0.70f, 0.6f, 0.9f};
	scene->obj[4].color = (t_vec4){0.2f, 0.2f, 1.0f, 0.0f};
	scene->obj[4].mat = (t_vec4){0, 0, 0, 0};

	scene->obj[5].type = (t_vec4){1.0f, 0.0f, 0.0f, 0.0f};
	scene->obj[5].sphere.origin = (t_vec4){0.0f, -25.0f, 0.0f, 25.0f};
	scene->obj[5].color = (t_vec4){1.0f, 0.2f, 0.2f, 0.0f};
	scene->obj[5].mat = (t_vec4){0.2, 0, 0, 0};


	// Sphere sphere[objNum] = {{ {75.0f, 25.0f, 0.0f, 60.0f}, {1.0f, 1.0f, 1.0f, 0.0f}, {0.0,1,0,0} },
	
	// 						{ {0.0f, 2.80f, -3.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 0.0f}, {1.0f,0,0,0} },

	// 						{ {0.8f, 0.35f, -2.3f, 0.5f}, {1.0f, 1.0f, 1.0f, 0.0f}, {0,0,0,0} },
	// 						{ {0.0f, 0.70f, -1.0f, 0.75f}, {0.2f, 1.0f, 0.2f, 0.0f}, {0,0,0,0} },
	// 						{ {-0.9f, 0.70f, 0.6f, 0.9f}, {0.2f, 0.2f, 1.0f, 0.0f}, {0,0,0,0} },
							

	// 						{ {0.0f, -25.0f, 0.0f, 25.0f}, {1.0f, 0.2f, 0.2f, 0.0f}, {0.2,0,0,0} }};


	// scene->obj[0].origin = (t_vec4){0.0f, -25.0f, 0.0f, 25.0f};
	// scene->obj[0].color = (t_vec4){1.0f, 1.0f, 1.0f, 1.0f};
	// scene->obj[0].mat = (t_vec4){0.0f, 1.0f, 0.0f, 0.0f};

	// for (int i = 1; i < objNum - 1; i++)
	// {
	// 	scene->obj[i].origin = (t_vec4){(float)(rand() % 100 - 50), (float)(rand() % 100 - 50), (float)(rand() % 100 - 50), (float)(rand() % 100) / 50 + 0.01};
	// 	scene->obj[i].color = (t_vec4){(float)(rand() % 100) / 100, (float)(rand() % 100) / 100, (float)(rand() % 100) / 100, 1.0f};
	// 	scene->obj[i].mat = (t_vec4){(float)(rand() % 100) / 100, 0.0f, 0.0f, 0.0f};
	// }

	// for (int i = 0; i < objNum; i++)
		// scene->obj[i].sphere = sphere[i];

	scene->camera.origin = (t_vec4){2.0f, 2, 2.0f};
}