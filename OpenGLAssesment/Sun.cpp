#include "Sun.h"

Sun::Sun(std::vector<Planet*>& planets)
{
	this->planets_ = planets;
}

void Sun::addPlanet(Planet* planet)
{
	this->planets_.push_back(planet);
}

void Sun::draw() const
{
}

void Sun::update(float deltatime) const
{
}
