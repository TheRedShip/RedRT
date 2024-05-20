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

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
    vec3 center;
    float radius;
    vec3 color;
} Sphere;

static vec2 vertices[6] = {
    { -1.0f, -1.0f }, { 1.0f, -1.0f }, { -1.0f, 1.0f },
    { 1.0f, -1.0f }, { 1.0f,  1.0f }, { -1.0f, 1.0f }
};

static const char* vertex_shader_text = "#version 330 core\n"
    "layout(location = 0) in vec2 vPos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(vPos, 0.0, 1.0);\n"
    "}\n";

static const char* fragment_shader_text = "#version 330 core\n"
    "out vec4 fragColor;\n"
    "uniform vec2 resolution;\n"
    "layout(std140) uniform Sphere {\n"
    "    vec3 center;\n"
    "    float radius;\n"
    "    vec3 color;\n"
    "};\n"
    "bool raySphereIntersect(vec3 rayOrigin, vec3 rayDir, vec3 center, float radius, out vec3 hitPoint) {\n"
    "    vec3 oc = rayOrigin - center;\n"
    "    float a = dot(rayDir, rayDir);\n"
    "    float b = 2.0 * dot(oc, rayDir);\n"
    "    float c = dot(oc, oc) - radius * radius;\n"
    "    float discriminant = b * b - 4 * a * c;\n"
    "    if (discriminant < 0.0) return false;\n"
    "    float t = (-b - sqrt(discriminant)) / (2.0 * a);\n"
    "    hitPoint = rayOrigin + t * rayDir;\n"
    "    return true;\n"
    "}\n"
    "void main() {\n"
    "    vec2 uv = gl_FragCoord.xy / resolution;\n"
    "    vec3 rayOrigin = vec3(0.0, 0.0, 0.0);\n"
    "    vec3 rayDir = normalize(vec3(uv * 2.0 - 1.0, -1.0));\n"
    "    vec3 hitPoint;\n"
    "    if (raySphereIntersect(rayOrigin, rayDir, center, radius, hitPoint)) {\n"
    "        fragColor = vec4(color, 1.0);\n"
    "    } else {\n"
    "        fragColor = vec4(0.0, 0.0, 0.0, 1.0);\n"
    "    }\n"
    "}\n";

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

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
    glfwSwapInterval(0);

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    GLint resolution_location = glGetUniformLocation(program, "resolution");

    GLuint vertex_array;
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vec2), (void*)0);

    // Sphere data
    Sphere sphere = { {0.0f, 0.0f, -5.0f}, 1.0f, {1.0f, 0.0f, 0.0f} };
    
    GLuint sphere_ubo;
    glGenBuffers(1, &sphere_ubo);
    glBindBuffer(GL_UNIFORM_BUFFER, sphere_ubo);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(Sphere), &sphere, GL_DYNAMIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, sphere_ubo);

    GLuint sphere_index = glGetUniformBlockIndex(program, "Sphere");
    glUniformBlockBinding(program, sphere_index, 0);

     double previousTime = glfwGetTime();
    int frameCount = 0;

    while (!glfwWindowShouldClose(window)) {
        double currentTime = glfwGetTime();
        frameCount++;

        if (currentTime - previousTime >= 1.0) {
            printf("FPS: %d\n", frameCount);

            frameCount = 0;
            previousTime = currentTime;
        }

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glUniform2f(resolution_location, (float)width, (float)height);
        
        // Update sphere position or other properties here if needed
        sphere.center[0] = 0.5f * sin(glfwGetTime());  // Example of moving the sphere
        glBindBuffer(GL_UNIFORM_BUFFER, sphere_ubo);
        glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(Sphere), &sphere);

        glBindVertexArray(vertex_array);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}