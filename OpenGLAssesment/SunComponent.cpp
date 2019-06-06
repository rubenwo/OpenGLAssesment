#include "SunComponent.hpp"
#include <GL/freeglut.h>

SunComponent::SunComponent()
{
}

SunComponent::~SunComponent()
{
}


void SunComponent::draw()
{
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	//glutSolidSphere(0.25, 30, 20);

	glutWireCube(0.25);
	glPopMatrix();
}
