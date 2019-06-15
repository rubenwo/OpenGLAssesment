#pragma once
#include "Renderer.h"

class Moon : public IRenderable
{
public:
	Moon() = default;
	~Moon() = default;

	void draw() const override;
	void update(float deltatime) const override;
};
