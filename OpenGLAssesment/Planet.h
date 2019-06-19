#pragma once
#include "Renderer.h"

class Planet : public IRenderable
{
public:
	Planet() = default;
	Planet(Vec3f& pos);
	~Planet() = default;
	void draw() const override;
	void update(float deltatime) const override;
};
