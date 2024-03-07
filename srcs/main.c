/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:14:15 by marvin            #+#    #+#             */
/*   Updated: 2024/03/03 20:14:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <windows.h>
#include <GL/glut.h>

void	display()
{
}

void init() 
{
	glClearColor(0.000, 0.110, 0.392, 0.0); // JMU Gold

	glColor3f(0.314, 0.314, 0.000); // JMU Purple

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Test");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}