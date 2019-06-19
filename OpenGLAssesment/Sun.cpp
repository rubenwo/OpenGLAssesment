#include "Sun.h"
#include <GL/freeglut.h>
#include "Globals.hpp"
#include <string>
float s;

Sun::Sun(std::string texturePath)
{
	s = 0;
	position = {0, 0, 0};
	rotation = {0, 0, 0};
	Image* t = loadBMP(texturePath.c_str());
	texture = loadTexture(t);
	delete t;
}

Sun::~Sun()
{
}


void Sun::draw() const
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLUquadricObj* quadric;
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);


	glDisable(GL_LIGHTING);

	glPushMatrix();
	glRotatef(s, 0, 1, 0);
	glColor3f(0.8, 0.498039, 0.196078);
	gluSphere(quadric, 15, 36, 18);
	//glColor3f(1, 1, 0);
	glEnable(GL_BLEND);
	glBlendFunc(1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, 20, 36, 18);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	glEnable(GL_LIGHTING);
	GLfloat light_position[] = {0.0, 0.0, 0.0, 1};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	GLfloat light_diff[] = {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diff);
	GLfloat light_amb[] = {0.0, 0.0, 0.0, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
	//gluDeleteQuadric(quadric);
}

void Sun::update(float deltatime) const
{
	s += 0.1f;
}
