/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:25:02 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 14:25:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "RT.h"

void	move_camera(t_vec4 movement);

void	cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void	error_callback(int error, const char* description);
void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void	apply_rotation_matrix_x(float angle, float (*matrix)[4]);
void	apply_rotation_matrix_y(float angle, float (*matrix)[4]);
int		getFPScounter();

void	variableToShader(GLuint program);

#endif