#pragma once
#include "Drawable.hpp"
#include "Vec.h"

class Planet : public Drawable
{
private:
	Vec3f pos;
	Vec3f speed;
public:
	Planet();
	Planet(Vec3f& pos, Vec3f& speed);
	~Planet() = default;
	void draw() const override;
};
