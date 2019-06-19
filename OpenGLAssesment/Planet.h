#pragma once
#include "Renderer.h"
#include <GL/freeglut.h>

class Planet : public IRenderable
{
private:
	float size;
	GLuint texture;
public:
	Planet() = default;
	Planet(Vec3f& pos, GLuint texture, float size);
	~Planet() = default;
	void draw() const override;
	void update(float deltatime) const override;
};
