#pragma once
#include "Renderer.h"

class Planet : public IRenderable
{
private:
	float size;
public:
	Planet() = default;
	Planet(Vec3f& pos, float size);
	~Planet() = default;
	void draw() const override;
	void update(float deltatime) const override;
};
