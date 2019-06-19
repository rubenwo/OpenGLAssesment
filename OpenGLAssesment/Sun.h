#pragma once
#include "Renderer.h"

class Sun : public IRenderable
{
public:
	Sun();
		~Sun();
	void draw() const override;
	void update(float deltatime) const override;
};
