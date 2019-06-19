#pragma once
#include "Renderer.h"
#include <GL/freeglut.h>

class Sun : public IRenderable
{
private:
	GLuint texture;

public:
	Sun(std::string texturePath);
	~Sun();
	void draw() const override;
	void update(float deltatime) const override;
};
