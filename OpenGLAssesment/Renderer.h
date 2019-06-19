#pragma once
#include <vector>
#include "Vec.h"


class IRenderable
{
public:
	IRenderable() = default;
	~IRenderable() = default;
	Vec3f position;
	Vec3f rotation;

	virtual void draw() const
	{
	}

	virtual void update(float deltatime) const
	{
	}
};

class Renderer
{
	std::vector<IRenderable*> renderables_;
public:
	Renderer() = default;
	~Renderer() = default;

	void add_renderable(IRenderable* r);
	void update(float deltatime);
	void draw();
};
