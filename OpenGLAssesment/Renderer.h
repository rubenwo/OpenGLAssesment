#pragma once
#include <vector>
#include "Vec.hpp"

class IRenderable
{
private:
public:
	Vec3f position;

	IRenderable() = default;

	IRenderable(Vec3f position)
	{
		this->position = position;
	}


	virtual void update(float deltatime) const
	{
	}

	virtual void draw() const
	{
	}
};


class Renderer
{
private:
	std::vector<IRenderable*> renderables_;
public:
	Renderer() = default;
	~Renderer() = default;

	void addRenderable(IRenderable* renderable);
	void update(float deltatime);
	void draw();
};
