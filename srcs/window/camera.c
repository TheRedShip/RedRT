/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:47:19 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 01:47:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

extern Scene scene;

t_vec4 multiply_matrix_vector(float (*m)[4], t_vec4 vector)
{
	t_vec4 result;

	result.x = m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z;
	result.y = m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z;
	result.z = m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z;

	return (result);
}

void	move_camera(t_vec4 movement)
{
	t_vec4	rotate_movement;


	rotate_movement = multiply_matrix_vector(scene.camera.rotation_matrix_x, movement);
	rotate_movement = multiply_matrix_vector(scene.camera.rotation_matrix_y, rotate_movement);
	
	scene.camera.origin.x += rotate_movement.x;
	scene.camera.origin.y += rotate_movement.y;
	scene.camera.origin.z += rotate_movement.z;
}

void	cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	static double lastX = 0;
	static double lastY = 0;

	if (lastX == 0 && lastY == 0)
	{
		lastX = xpos;
		lastY = ypos;
	}
	double xoffset = xpos - lastX;
	double yoffset = lastY - ypos;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) 
	{
		scene.camera.direction.x += yoffset * 0.002f;
		scene.camera.direction.y += xoffset * 0.002f;
		
		scene.frameCount = 0;
	}

	lastX = xpos;
	lastY = ypos;
}