#include <GL/glew.h>
#include <gl/freeglut.h>
#include "Simulation.h"
#include "Globals.hpp"

Simulation simulation;

void display_func(void)
{
	simulation.display_func();
}

void reshape_func(int width, int height)
{
	simulation.reshape_func(width, height);
}

void idle_func(void)
{
	simulation.idle_func();
}


void mouse_func(int button, int state, int x, int y)
{
	simulation.mouse_func(button, state, x, y);
}

void mouse_wheel_func(int wheel, int direction, int x, int y)
{
	simulation.mouse_wheel_func(wheel, direction, x, y);
}

void keyboard_func(unsigned char key, int x, int y)
{
	simulation.keyboard_func(key, x, y);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 2);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(APPLICATION_NAME);
	glutDisplayFunc(display_func);
	glutReshapeFunc(reshape_func);
	glutMouseFunc(mouse_func);
	glutKeyboardFunc(keyboard_func);
	glutMouseWheelFunc(mouse_wheel_func);
	glutIdleFunc(idle_func);

	glewExperimental = GL_TRUE;
	glewInit();

	glutMainLoop();

	return 0;
}
