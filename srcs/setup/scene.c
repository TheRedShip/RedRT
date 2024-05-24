/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:04:41 by marvin            #+#    #+#             */
/*   Updated: 2024/05/24 17:12:51 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

void	init_scene(Scene *scene, Object *object)
{
	object[0].sphere.origin = (t_vec4){75.0f, 25.0f, 0.0f, 60.0f};
	object[0].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	object[0].mat = (t_vec4){0.0, 1, 0, 0};
	object[0].type = 1;

	object[1].sphere.origin = (t_vec4){0.0f, 2.80f, -3.0f, 1.0f};
	object[1].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	object[1].mat = (t_vec4){1.0f, 0, 0, 0};
	object[1].type = 1;

	object[2].sphere.origin = (t_vec4){0.8f, 0.35f, -2.3f, 0.5f};
	object[2].color = (t_vec4){1.0f, 1.0f, 1.0f, 0.0f};
	object[2].mat = (t_vec4){0, 0, 0, 0};
	object[2].type = 1;

	object[3].sphere.origin = (t_vec4){0.0f, 0.70f, -1.0f, 0.75f};
	object[3].color = (t_vec4){0.2f, 1.0f, 0.2f, 0.0f};
	object[3].mat = (t_vec4){0, 0, 0, 0};
	object[3].type = 1;

	object[4].sphere.origin = (t_vec4){-0.9f, 0.70f, 0.6f, 0.9f};
	object[4].color = (t_vec4){0.2f, 0.2f, 1.0f, 0.0f};
	object[4].mat = (t_vec4){0, 0, 0, 0};\
	object[4].type = 1;

	object[5].sphere.origin = (t_vec4){0.0f, -25.0f, 0.0f, 25.0f};
	object[5].color = (t_vec4){1.0f, 0.2f, 0.2f, 0.0f};
	object[5].mat = (t_vec4){0.2, 0, 0, 0};
	object[5].type = 1;
	
	// object[0].sphere.origin = (t_vec4){0,4,0,0.5};
	// object[0].color = (t_vec4){1.0f, 1.0f, 1.0f,0};
	// object[0].mat = (t_vec4){0,5,0,0};
	// object[0].type = 1;

	// object[1].sphere.origin = (t_vec4){0,0.5,0,1};
	// object[1].color = (t_vec4){1.0f, 1.0f, 1.0f,0};
	// object[1].mat = (t_vec4){1,0,0,0};
	// object[1].type = 1;

	// object[2].sphere.origin = (t_vec4){1.5,0.25,0,0.5};
	// object[2].color = (t_vec4){1.0f, 0.0f, 0.0f,0};
	// object[2].mat = (t_vec4){0,0,0,0};
	// object[2].type = 1;

	// object[3].sphere.origin = (t_vec4){-1.5,0.25,0,0.5};
	// object[3].color = (t_vec4){0.0f, 1.0f, 0.0f,0};
	// object[3].mat = (t_vec4){0,0,0,0};
	// object[3].type = 1;

	// object[4].sphere.origin = (t_vec4){0,0.25,-1.5,0.5};
	// object[4].color = (t_vec4){0.0f, 0.0f, 1.0f,0};
	// object[4].mat = (t_vec4){0,0,0,0};
	// object[4].type = 1;

	// object[5].plane.origin = (t_vec4){0,0,0,0};
	// object[5].plane.normal = (t_vec4){0,1,0,0};
	// object[5].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	// object[5].mat = (t_vec4){0.995,0,0,0};
	// object[5].type = 2;

	// object[6].plane.origin = (t_vec4){0,0,-4,0};
	// object[6].plane.normal = (t_vec4){0,0,1,0};
	// object[6].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	// object[6].mat = (t_vec4){0.995,0,0,0};
	// object[6].type = 2;

	// object[7].plane.origin = (t_vec4){0,0,4,0};
	// object[7].plane.normal = (t_vec4){0,0,-1,0};
	// object[7].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	// object[7].mat = (t_vec4){0.995,0,0,0};
	// object[7].type = 2;

	// object[8].plane.origin = (t_vec4){4,0,0,0};
	// object[8].plane.normal = (t_vec4){-1,0,0,0};
	// object[8].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	// object[8].mat = (t_vec4){0.995,0,0,0};
	// object[8].type = 2;

	// object[9].plane.origin = (t_vec4){-4,0,0,0};
	// object[9].plane.normal = (t_vec4){1,0,0,0};
	// object[9].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	// object[9].mat = (t_vec4){0.995,0,0,0};
	// object[9].type = 2;

	// object[10].plane.origin = (t_vec4){0,10,0,0};
	// object[10].plane.normal = (t_vec4){0,-1,0,0};
	// object[10].color = (t_vec4){0.8f, 0.8f, 0.8f,0};
	// object[10].mat = (t_vec4){0.995,0,0,0};
	// object[10].type = 2;
	
	object[0].plane.origin = (t_vec4){0,3,0,0};
	object[0].plane.normal = (t_vec4){0,1,0,0};
	object[0].color = (t_vec4){1.0f,1.0f,1.0f,0};
	object[0].mat = (t_vec4){0,1,0,0};
	object[0].type = 2;

	object[1].plane.origin = (t_vec4){0,0,-3,0};
	object[1].plane.normal = (t_vec4){0,0,1,0};
	object[1].color = (t_vec4){0.25f,0.25f,0.25f,0};
	object[1].mat = (t_vec4){0,0,0,0};
	object[1].type = 2;
	
	object[2].plane.origin = (t_vec4){3,0,0,0};
	object[2].plane.normal = (t_vec4){-1,0,0,0};
	object[2].color = (t_vec4){0.1f,0.1f,1.0f,0};
	object[2].mat = (t_vec4){0,0,0,0};
	object[2].type = 2;
	
	object[3].plane.origin = (t_vec4){-3,0,0,0};
	object[3].plane.normal = (t_vec4){1,0,0,0};
	object[3].color = (t_vec4){1.0f,0.1f,0.1f,0};
	object[3].mat = (t_vec4){0,0,0,0};
	object[3].type = 2;

	object[4].plane.origin = (t_vec4){0,-3,0,0};
	object[4].plane.normal = (t_vec4){0,1,0,0};
	object[4].color = (t_vec4){1.0f,1.0f,1.0f,0};
	object[4].mat = (t_vec4){0,0,0,0};
	object[4].type = 2;

	object[5].plane.origin = (t_vec4){0,0,-3,0};
	object[5].plane.normal = (t_vec4){0,0,-1,0};
	object[5].color = (t_vec4){1.0f,1.0f,1.0f,0};
	object[5].mat = (t_vec4){0,0,0,0};
	object[5].type = 2;

	object[6].plane.origin = (t_vec4){0,0,3,0};
	object[6].plane.normal = (t_vec4){0,0,-1,0};
	object[6].color = (t_vec4){1.0f,1.0f,1.0f,0};
	object[6].mat = (t_vec4){0,0,0,0};
	object[6].type = 2;

	object[7].sphere.origin = (t_vec4){0,-2,0,1};
	object[7].color = (t_vec4){1.0f,1.0f,1.0f,0};
	object[7].mat = (t_vec4){1,0,0,0};
	object[7].type = 1;

	object[8].sphere.origin = (t_vec4){2,-2.25,0,0.75};
	object[8].color = (t_vec4){0.08f,0.5f,0.08f,0};
	object[8].mat = (t_vec4){0,0,0,0};
	object[8].type = 1;

	object[9].sphere.origin = (t_vec4){-2,-2.25,0,0.75};
	object[9].color = (t_vec4){0.5f,0.08f,0.5f,0};
	object[9].mat = (t_vec4){0,0,0,0};
	object[9].type = 1;

	// lq	-3,3,-3				6,0,0			0,0,6					255,255,255		1

	// pl	0,0,-3				0,0,1									50,50,50		1.0,0.0
	// pl	3,0,0				-1,0,0									20,20,255		1.0,0.0
	// pl	-3,0,0				1,0,0									255,20,20		1.0,0.0
	// pl	0,-3,0				0,1,0									255,255,255		1.0,0.0
	// pl	0,0,-3				0,0,-1									255,255,255		1.0,0.0
	// pl	0,0,3				0,0,-1									255,255,255		1.0,0.0

	// gc	-1,-2,0			2	4			0,0,0					255,255,255		1.8
	// sp	-2,-2.25,0			1.5										20,100,20		1.0,0.05
	// sp	2,-2.25,0			1.5										100,20,100		1.0,0.05

	scene->camera.origin = (t_vec4){0,0,2.9};
}