#include "Renderer.h"


void Renderer::add_renderable(IRenderable* r)
{
	renderables_.push_back(r);
}


void Renderer::draw()
{
	for (auto r : renderables_)
	{
		r->draw();
	}
}

void Renderer::update(float deltatime)
{
	for (auto r : renderables_)
	{
		r->update(deltatime);
	}
}
