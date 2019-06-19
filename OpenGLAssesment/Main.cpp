#include <GL/freeglut.h>
#include <GL/glut.h>
#include "Globals.hpp"
#include "Simulation.h"
#include <iostream>

bool initGlut(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInit(&argc, argv);
	glutCreateWindow(APPLICATION_NAME);
	glutDisplayFunc(Simulation::Render);
	glutReshapeFunc(Simulation::Reshape);
	glutIdleFunc(Simulation::Idle);
	glutKeyboardFunc(Simulation::OnKeyPressed);
	glutMouseWheelFunc(Simulation::OnMouseScroll);
	glutMotionFunc(Simulation::OnMouseActiveMove);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	return true;
}

bool initOpenGL()
{
	glEnable(GL_DEPTH_TEST);

	return true;
}


int main(int argc, char* argv[])
{
	if (initGlut(argc, argv))
		std::cout << "Succesfully initialized glut.\n";
	else
	{
		std::cout << "Failed initializing glut.\n";
		return GLUT_INIT_FAILED;
	}

	if (initOpenGL())
		std::cout << "Succesfully initialized OpenGL.\n";
	else
	{
		std::cout << "Failed initializing OpenGL.\n";
		return OPENGL_INIT_FAILED;
	}

	// Start loading in game content.
	Simulation::LoadContent();

	// Start game.
	glutMainLoop();

	Simulation::OnClose();

	return EXIT_SUCCESS;
}
