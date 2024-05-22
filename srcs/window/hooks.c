/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:25:59 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 14:25:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

extern Scene scene;

int		handle_movements(int key)
{
	if (key == GLFW_KEY_W)
		move_camera((t_vec4){0.0f, 0.0f, -0.1f});
	else if (key == GLFW_KEY_S)
		move_camera((t_vec4){0.0f, 0.0f, 0.1f});
	else if (key == GLFW_KEY_A)
		move_camera((t_vec4){-0.1f, 0.0f, 0.0f});
	else if (key == GLFW_KEY_D)
		move_camera((t_vec4){0.1f, 0.0f, 0.0f});
	else if (key == GLFW_KEY_Q)
		move_camera((t_vec4){0.0f, -0.1f, 0.0f});
	else if (key == GLFW_KEY_E)
		move_camera((t_vec4){0.0f, 0.1f, 0.0f});
	else
		return (0);
	return (1);
}

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	else if (key == GLFW_KEY_SPACE)
		scene.frameCount = 0;

	if (handle_movements(key))
		scene.frameCount = 0;
}

void	error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}