﻿#pragma once
#include "Renderer.h"
#include <GL/freeglut.h>

class Planet : public IRenderable
{
private:
	float size, speed;
	GLuint texture;

public:
	Planet() = default;
	Planet(Vec3f& pos, std::string texturePath, float size);
	~Planet() = default;
	void draw() const override;
	void update(float deltatime) const override;
};
