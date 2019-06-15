#include "Renderer.h"


void Renderer::addRenderable(IRenderable* renderable)
{
	this->renderables_.push_back(renderable);
}


void Renderer::draw()
{
	for (auto renderable : renderables_)
		renderable->draw();
}

void Renderer::update(float deltatime)
{
	for (auto renderable : renderables_)
		renderable->update(deltatime);
}
