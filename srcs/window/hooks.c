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

void	error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void	cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	static double lastX = 0;
	static double lastY = 0;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE) 
	{
		return;
	}

	if (lastX == 0 && lastY == 0)
	{
		lastX = xpos;
		lastY = ypos;
	}

	double xoffset = xpos - lastX;
	double yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	scene.frameCount = 0;
}

int		handle_movements(int key)
{
	if (key == GLFW_KEY_W)
		scene.camera.origin[2] -= 0.1;
	else if (key == GLFW_KEY_S)
		scene.camera.origin[2] += 0.1;
	else if (key == GLFW_KEY_A)
		scene.camera.origin[0] -= 0.1;
	else if (key == GLFW_KEY_D)
		scene.camera.origin[0] += 0.1;
	else if (key == GLFW_KEY_Q)
		scene.camera.origin[1] -= 0.1;
	else if (key == GLFW_KEY_E)
		scene.camera.origin[1] += 0.1;
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