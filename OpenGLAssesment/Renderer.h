#pragma once
#include <vector>
#include "Vec.h"

class IRenderable
{
private:
	Vec3f position;
public:
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
