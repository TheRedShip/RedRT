/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:31:00 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 19:31:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

void	apply_rotation_matrix_x(float angle, float (*matrix)[4])
{
	float	cos_theta;
	float	sin_theta;

	cos_theta = cos(angle);
	sin_theta = sin(angle);
	matrix[0][0] = 1.0f;
	matrix[0][1] = 0.0f;
	matrix[0][2] = 0.0f;
	matrix[1][0] = 0.0f;
	matrix[1][1] = cos_theta;
	matrix[1][2] = -sin_theta;
	matrix[2][0] = 0.0f;
	matrix[2][1] = sin_theta;
	matrix[2][2] = cos_theta;
}

void	apply_rotation_matrix_y(float angle, float (*matrix)[4])
{
	float	cos_theta;
	float	sin_theta;

	cos_theta = cos(angle);
	sin_theta = sin(angle);
	matrix[0][0] = cos_theta;
	matrix[0][1] = 0.0f;
	matrix[0][2] = -sin_theta;
	matrix[1][0] = 0.0f;
	matrix[1][1] = 1.0f;
	matrix[1][2] = 0.0f;
	matrix[2][0] = sin_theta;
	matrix[2][1] = 0.0f;
	matrix[2][2] = cos_theta;
}

int	getFPScounter()
{
	static int		fps = 0;
	static double	previousTime = 0;
	double			currentTime = glfwGetTime();
	
	if (previousTime == 0)
		previousTime = glfwGetTime();
	
	
	fps++;
	if (currentTime - previousTime >= 1.0)
	{
		printf("FPS: %d\n", fps);
		
		fps = 0;
		previousTime = currentTime;
	}
	return (fps);
}