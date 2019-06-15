#include "renderer.h"
#include <GLFW/glfw3.h>


renderer::renderer(GLFWwindow* window)
{
	this->window = window;
}


void renderer::add_drawable(drawable& d)
{
	drawables_.push_back(d);
}

void renderer::render_scene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto drawable : drawables_)
		drawable.draw();

	glfwSwapBuffers(window);
}
