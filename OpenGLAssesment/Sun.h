#pragma once
#include "drawable.h"

class Sun : public drawable
{
public:
	Sun();
	~Sun();

	void draw() const override;
};
