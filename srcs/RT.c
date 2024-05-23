/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:37:38 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 01:37:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

Scene 	scene;
Object	object[objNum];

int main(void)
{
	init_scene(&scene, object);

	GLFWwindow *window = setupGLFW();
	GLuint program = setupShaderProgram();

	GLuint vertex_array;
	glGenVertexArrays(1, &vertex_array);
	glBindVertexArray(vertex_array);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vec2), (void*)0);

	GLuint scene_buffer;
	glGenBuffers(1, &scene_buffer);
	glBindBuffer(GL_UNIFORM_BUFFER, scene_buffer);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(scene), &scene, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);

	GLuint scene_block = glGetUniformBlockIndex(program, "SceneBlock");
	glUniformBlockBinding(program, scene_block, 0);
	glBindBufferBase(GL_UNIFORM_BUFFER, scene_block, scene_buffer);

	GLuint object_buffer;
	glGenBuffers(1, &object_buffer);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, object_buffer);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(Object) * objNum, &object, GL_STATIC_DRAW);

	GLuint object_binding = 1;
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, object_binding, object_buffer);



	GLuint currentFrameTex, accumFrameTex, framebuffer;
    glGenTextures(1, &currentFrameTex);
    glBindTexture(GL_TEXTURE_2D, currentFrameTex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenTextures(1, &accumFrameTex);
    glBindTexture(GL_TEXTURE_2D, accumFrameTex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, currentFrameTex, 0);

	while (!glfwWindowShouldClose(window))
	{
		apply_rotation_matrix_x(scene.camera.direction.x, scene.camera.rotation_matrix_x);
		apply_rotation_matrix_y(scene.camera.direction.y, scene.camera.rotation_matrix_y);

		scene.frameCount++;
		getFPScounter();

		glViewport(0, 0, WIDTH, HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

		variableToShader(program);
		glBindBufferBase(GL_UNIFORM_BUFFER, scene_block, scene_buffer);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(scene), &scene);

		// glBindBufferBase(GL_UNIFORM_BUFFER, sphere_block, sphere_buffer);
		// glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(Sphere) * objNum, &object.sphere);

		glBindVertexArray(vertex_array);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glUseProgram(program);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, currentFrameTex);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, accumFrameTex);

		glBindVertexArray(vertex_array);
        glDrawArrays(GL_TRIANGLES, 0, 6);

		GLuint temp = currentFrameTex;
        currentFrameTex = accumFrameTex;
        accumFrameTex = temp;

        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, currentFrameTex, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}