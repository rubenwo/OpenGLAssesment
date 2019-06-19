#include "Planet.h"
#include <GL/freeglut.h>

Vec3f rot;
Planet::Planet(Vec3f& pos, float size)
{
	position = pos;
	rotation = {0, 0, 0};
	rot = rotation;
	this->size = size;
}

void Planet::draw() const
{
	GLUquadricObj* quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluDeleteQuadric(quadric);

	glPushMatrix(); //1 planet
	glRotatef(rot.y, 0, 1, 0);
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rot.x, 1, 0, 0);
	glColor3f(1, 0, 0);
	gluSphere(quadric, size, 36, 18);
	glPopMatrix();
}

void Planet::update(float deltatime) const
{
	rot.x += 0.1f;
	rot.y += 0.1f;
}
