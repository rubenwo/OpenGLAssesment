#include "renderer.h"


renderer::renderer(GLFWwindow* window, Camera& camera)
{
	this->window = window;
	this->camera_ = camera;
}


void renderer::add_drawable(drawable* d)
{
	drawables_.push_back(d);
}

void renderer::set_camera(Camera& camera)
{
	this->camera_ = camera;
}


void renderer::render_scene()
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);


	for (auto drawable : drawables_)
	{

		(*drawable).draw();

	}

	glfwSwapBuffers(window);
}
