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

void	init_scene(Scene *scene, Object *object)
{
	// object[0].sphere.origin = (t_vec4){75.0f, 25.0f, 0.0f, 60.0f};
	// object[0].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	// object[0].mat = (t_vec4){0.0, 1, 0, 0};
	// object[0].type = 1;

	// object[1].sphere.origin = (t_vec4){0.0f, 2.80f, -3.0f, 1.0f};
	// object[1].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	// object[1].mat = (t_vec4){1.0f, 0, 0, 0};
	// object[1].type = 1;

	// object[2].sphere.origin = (t_vec4){0.8f, 0.35f, -2.3f, 0.5f};
	// object[2].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	// object[2].mat = (t_vec4){0, 0, 0, 0};
	// object[2].type = 1;

	// object[3].sphere.origin = (t_vec4){0.0f, 0.70f, -1.0f, 0.75f};
	// object[3].color = (t_vec4){0.2f, 1.0f, 0.2f, 0.0f};
	// object[3].mat = (t_vec4){0, 0, 0, 0};
	// object[3].type = 1;

	// object[4].sphere.origin = (t_vec4){-0.9f, 0.70f, 0.6f, 0.9f};
	// object[4].color = (t_vec4){0.2f, 0.2f, 1.0f, 0.0f};
	// object[4].mat = (t_vec4){0, 0, 0, 0};\
	// object[4].type = 1;

	// object[5].sphere.origin = (t_vec4){0.0f, -25.0f, 0.0f, 25.0f};
	// object[5].color = (t_vec4){1.0f, 0.2f, 0.2f, 0.0f};
	// object[5].mat = (t_vec4){0.2, 0, 0, 0};
	// object[5].type = 1;
	
	object[0].sphere.origin = (t_vec4){0,4,0,0.5};
	object[0].color = (t_vec4){1.0f, 1.0f, 1.0f,0};
	object[0].mat = (t_vec4){0,5,0,0};
	object[0].type = 1;

	object[1].sphere.origin = (t_vec4){0,0.5,0,1};
	object[1].color = (t_vec4){1.0f, 1.0f, 1.0f,0};
	object[1].mat = (t_vec4){1,0,0,0};
	object[1].type = 1;

	object[2].sphere.origin = (t_vec4){1.5,0.25,0,0.5};
	object[2].color = (t_vec4){1.0f, 0.0f, 0.0f,0};
	object[2].mat = (t_vec4){0,0,0,0};
	object[2].type = 1;

	object[3].sphere.origin = (t_vec4){-1.5,0.25,0,0.5};
	object[3].color = (t_vec4){0.0f, 1.0f, 0.0f,0};
	object[3].mat = (t_vec4){0,0,0,0};
	object[3].type = 1;

	object[4].sphere.origin = (t_vec4){0,0.25,-1.5,0.5};
	object[4].color = (t_vec4){0.0f, 0.0f, 1.0f,0};
	object[4].mat = (t_vec4){0,0,0,0};
	object[4].type = 1;

	object[5].plane.origin = (t_vec4){0,0,0,0};
	object[5].plane.normal = (t_vec4){0,1,0,0};
	object[5].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	object[5].mat = (t_vec4){0.995,0,0,0};
	object[5].type = 2;

	object[6].plane.origin = (t_vec4){0,0,-4,0};
	object[6].plane.normal = (t_vec4){0,0,1,0};
	object[6].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	object[6].mat = (t_vec4){0.995,0,0,0};
	object[6].type = 2;

	object[7].plane.origin = (t_vec4){0,0,4,0};
	object[7].plane.normal = (t_vec4){0,0,-1,0};
	object[7].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	object[7].mat = (t_vec4){0.995,0,0,0};
	object[7].type = 2;

	object[8].plane.origin = (t_vec4){4,0,0,0};
	object[8].plane.normal = (t_vec4){-1,0,0,0};
	object[8].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	object[8].mat = (t_vec4){0.995,0,0,0};
	object[8].type = 2;

	object[9].plane.origin = (t_vec4){-4,0,0,0};
	object[9].plane.normal = (t_vec4){1,0,0,0};
	object[9].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	object[9].mat = (t_vec4){0.995,0,0,0};
	object[9].type = 2;

	object[10].plane.origin = (t_vec4){0,10,0,0};
	object[10].plane.normal = (t_vec4){0,-1,0,0};
	object[10].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	object[10].mat = (t_vec4){0.995,0,0,0};
	object[10].type = 2;
	



	scene->camera.origin = (t_vec4){0,3,4};
}