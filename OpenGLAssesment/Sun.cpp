#include "Sun.h"
#include <GL/freeglut.h>

void Sun::draw() const
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLUquadricObj* quadric;
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluDeleteQuadric(quadric);


	glDisable(GL_LIGHTING);

	glPushMatrix();
	glColor3f(0.8, 0.498039, 0.196078);
	gluSphere(quadric, 15, 36, 18);
	glColor3f(1, 1, 0);
	glEnable(GL_BLEND);
	glBlendFunc(1, 1);
	gluSphere(quadric, 20, 36, 18);
	glDisable(GL_BLEND);
	glPopMatrix();

	glEnable(GL_LIGHTING);
	GLfloat light_position[] = { 0.0, 0.0, 0.0, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	GLfloat light_diff[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diff);
	GLfloat light_amb[] = { 0.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
}

void Sun::update(float deltatime) const
{
}
