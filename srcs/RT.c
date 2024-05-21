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

int frameCount = 0;

static vec2 vertices[6] = {
	{ -1.0f, -1.0f }, { 1.0f, -1.0f }, { -1.0f, 1.0f },
	{ 1.0f, -1.0f }, { 1.0f,  1.0f }, { -1.0f, 1.0f }
};

int main(void) {
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "OpenGL Raytracer", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);

	const char *fragment_shader_text = load_file("srcs/shader/frag.glsl");
	const char *vertex_shader_text = load_file("srcs/shader/vertex.glsl");

	GLuint vertex_buffer;
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
	glCompileShader(vertex_shader);

	GLint success = 0;
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
	}
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
	glCompileShader(fragment_shader);

	success = 0;
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
	}

	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	GLint resolution_location = glGetUniformLocation(program, "resolution");
	GLint numberObjects_location = glGetUniformLocation(program, "numberObjects");
	GLint uTime_location = glGetUniformLocation(program, "uTime");

	GLuint vertex_array;
	glGenVertexArrays(1, &vertex_array);
	glBindVertexArray(vertex_array);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vec2), (void*)0);

	// Sphere data
	Sphere spheres[objNum] = {{ {0.0f, 1.5f, -5.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 0.0f}, {0.0,1,0,0} },
						{ {0.0f, 0.0f, -5.0f, 0.3f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.5,0,0,0} },
						{ {0.0f, -1.5f, -5.0f, 1.0f}, {1.0f, 0.0f, 0.0f, 0.0f}, {0.5,0,0,0} }};
	

	GLuint sphere_buffer;
	glGenBuffers(1, &sphere_buffer);
	glBindBuffer(GL_UNIFORM_BUFFER, sphere_buffer);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(spheres), spheres, GL_STATIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);

	GLuint blockIndex = glGetUniformBlockIndex(program, "SphereBlock");
	glUniformBlockBinding(program, blockIndex, 0);
	glBindBufferBase(GL_UNIFORM_BUFFER, 0, sphere_buffer);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	GLuint currentFrameTex, accumFrameTex, framebuffer;
    glGenTextures(1, &currentFrameTex);
    glBindTexture(GL_TEXTURE_2D, currentFrameTex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenTextures(1, &accumFrameTex);
    glBindTexture(GL_TEXTURE_2D, accumFrameTex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, currentFrameTex, 0);


	double previousTime = glfwGetTime();
	int fps = 0;
	while (!glfwWindowShouldClose(window)) {
		double currentTime = glfwGetTime();
		fps++;
		frameCount++;

		if (currentTime - previousTime >= 1.0) {
			printf("FPS: %d\n", fps);

			fps = 0;
			previousTime = currentTime;
		}

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

		glUseProgram(program);
		glUniform2f(resolution_location, (float)width, (float)height);
		glUniform1i(numberObjects_location, objNum);
		glUniform1f(uTime_location, (float)(glfwGetTime()));
		glUniform1i(glGetUniformLocation(program, "uRand"), rand());
		glUniform1i(glGetUniformLocation(program, "uFrameCount"), frameCount);

		
		// spheres[0].origin[0] = 1.5 * cos(glfwGetTime());  // Example of moving the sphere
		// spheres[0].origin[1] = 1.5 * sin(glfwGetTime());  // Example of moving the sphere
		// spheres[2].origin[0] = 1.5 * -cos(glfwGetTime());  // Example of moving the sphere
		// spheres[2].origin[2] = 1.5 * sin(glfwGetTime()) - 5.0;  // Example of moving the sphere
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(spheres), &spheres);

		glBindVertexArray(vertex_array);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glUseProgram(program);
        glUniform1i(glGetUniformLocation(program, "currentFrame"), 0);
        glUniform1i(glGetUniformLocation(program, "accumFrame"), 1);
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