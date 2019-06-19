#include "Planet.h"
#include <GL/freeglut.h>
#include <random>
#include "Globals.hpp"

Vec3f rot;
float speed;

Planet::Planet(Vec3f& pos, GLuint texture, float size)
{
	position = pos;
	rotation = {0, 0, 0};
	rot = rotation;
	this->size = size;
	speed = random(1, 5);
	this->texture = texture;
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
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, size, 36, 18);
	glPopMatrix();
}

void Planet::update(float deltatime) const
{
	rot.x += speed / 10;
	rot.y += speed / 10;
}
