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