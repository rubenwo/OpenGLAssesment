#include <math.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <string.h>
#include "Visuals.h"
#include "Globals.hpp"

int main(int argc, char* argv[])
{
	// initialize GLUT library state
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);


	// Define the main window size and initial position 

	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	//glutInitWindowPosition(50, 50);

	// Create and label the main window
	glutCreateWindow(APPLICATION_NAME);

	// Configure various properties of the OpenGL rendering context
	Setup();

	// Callbacks for the GL and GLUT events:

	// The rendering function 
	glutDisplayFunc(Render);
	glutReshapeFunc(Resize);
	glutIdleFunc(Idle);
	glutKeyboardFunc(Keyboard);
	glutMouseWheelFunc(MouseWheel);

	//Enter main event handling loop
	glutMainLoop();
	return 0;
}
