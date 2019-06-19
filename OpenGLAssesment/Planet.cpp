#include "Planet.h"
#include "GL/glut.h"

float rotX = 0;
float rotY = 0;
float rotZ = 0;

Planet::Planet()
{
	this->pos = {0, 0, 0};
	this->speed = {0, 0, 0};
}


Planet::Planet(Vec3f& pos, Vec3f& speed)
{
	this->pos = pos;
	this->speed = speed;
}

void Planet::draw() const
{
	rotZ += 0.01;
	rotX += 0.01;
	GLUquadricObj* quadric;
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluDeleteQuadric(quadric);

	glPushMatrix(); // 4 planet
	glRotatef(rotX, 1, 0, 0);

	glTranslatef(this->pos.x, this->pos.y, this->pos.z);
	glRotatef(rotZ, 0, 0, 1);
	
	glColor3f(0, 1, 1);
	gluSphere(quadric, 11, 36, 18);
	glPopMatrix();
}
