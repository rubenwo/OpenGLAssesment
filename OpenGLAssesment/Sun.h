#pragma once
#include <vector>
#include "Planet.h"

class Sun : public IRenderable
{
	std::vector<Planet*> planets_;
public:
	Sun() = default;
	Sun(std::vector<Planet*>& planets);
	~Sun() = default;

	void addPlanet(Planet* planet);

	void draw() const override;
	void update(float deltatime) const override;
};
