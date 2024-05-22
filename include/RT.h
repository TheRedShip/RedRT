/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:34:57 by marvin            #+#    #+#             */
/*   Updated: 2024/05/19 19:34:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define WIDTH 1920
# define HEIGHT 1080
# define objNum 100

# define GLFW_INCLUDE_NONE
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>


# include "cglm/cglm.h"
# include "linmath.h"
# include "glad/gl.h"
# include "GLFW/glfw3.h"

typedef struct s_vec4 {
    float x;
    float y;
    float z;
	float w;
} t_vec4;

# include "obj_struct.h"
# include "parsing.h"
# include "window.h"
# include "setup.h"
# include "settings.h"


typedef struct s_scene
{
	Sphere	obj[objNum];
	Camera	camera;
	int		frameCount;
} Scene;

#endif