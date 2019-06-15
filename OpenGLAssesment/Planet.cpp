#include "Planet.h"
#include <GL/glew.h>

Planet::Planet(std::vector<Moon*>& moons_)
{
}

void Planet::addMoon(Moon* moon)
{
}

void Planet::draw() const
{
}

void Planet::update(float deltatime) const
{
	for (auto moon : moons_)
	{
		glPushMatrix();
		glRotatef(0.5, 1, 0, 0);

		glPopMatrix();
	}
}
