/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:51:27 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 18:51:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "RT.h"

typedef struct s_scene Scene;

void		init_scene(Scene *scene);

GLFWwindow	*setupGLFW(void);
GLuint		setupShaderProgram(void);

#endif