#pragma once
#include <vector>
#include "Moon.h"
#include "Renderer.h"

class Planet : public IRenderable
{
	std::vector<Moon*> moons_;
public:
	Planet() = default;
	Planet(std::vector<Moon*>& moons_);
	~Planet() = default;

	void addMoon(Moon* moon);

	void draw() const override;
	void update(float deltatime) const override;
};
