/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:49:52 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 19:49:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

extern Scene scene;

void	variableToShader(GLuint program)
{
	glUniform2f(glGetUniformLocation(program, "resolution"), (float)WIDTH, (float)HEIGHT);
	glUniform1f(glGetUniformLocation(program, "uTime"), (float)(glfwGetTime()));
	glUniform1i(glGetUniformLocation(program, "uRand"), rand());
	glUniform1i(glGetUniformLocation(program, "uFrameCount"), scene.frameCount);
	glUniform1i(glGetUniformLocation(program, "currentFrame"), 0);
}