#include <GL/freeglut.h>
#include <list>
#include "SimulationObject.hpp"
#include "DrawComponent.hpp"

SimulationObject::SimulationObject()
{
}

SimulationObject::~SimulationObject()
{
	for (auto& c : components)
	{
		if (c != nullptr)
			delete c;
	}

	components.clear();
}

void SimulationObject::addComponent(Component* component)
{
	component->setGameObject(this);
	components.push_back(component);

	if (!drawComponent)
		drawComponent = dynamic_cast<DrawComponent*>(component);
}

std::list<Component*> SimulationObject::getComponents()
{
	return components;
}


void SimulationObject::draw()
{
	if (!drawComponent)
		return;

	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);
	glScalef(scale.x, scale.y, scale.z);
	drawComponent->draw();

	glPopMatrix();
}

void SimulationObject::update(float elapsedTime)
{
	for (auto& c : components)
		c->update(elapsedTime);
}
