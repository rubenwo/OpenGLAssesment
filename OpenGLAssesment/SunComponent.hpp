#pragma once
#include "DrawComponent.hpp"

class SunComponent : public DrawComponent
{
public:
	SunComponent();
	~SunComponent();

	virtual void draw() override;
};
