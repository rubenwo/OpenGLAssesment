#pragma once

#include "Component.hpp"

class DrawComponent : public Component
{
public:
	DrawComponent();
	~DrawComponent();
	virtual void draw() = 0;
};
