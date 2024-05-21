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

void	cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void	error_callback(int error, const char* description);
void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int		getFPScounter();

void	variableToShader(GLuint program);

#endif