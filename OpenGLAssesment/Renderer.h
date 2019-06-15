#pragma once
#include <vector>

class IRenderable
{
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
	std::Vector<IRenderable> renderables_;
public:
	Renderer() = default;
	~Renderer() = default;

	void update(float deltatime);
	void draw();
};
