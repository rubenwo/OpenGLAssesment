#pragma once
#include "drawable.h"
#include <vector>
#include <GLFW/glfw3.h>

class renderer
{
private:
	std::vector<drawable> drawables_;
	GLFWwindow* window;

public:
	renderer() = default;
	renderer(GLFWwindow* window);
	~renderer() = default;

	void add_drawable(drawable& d);

	void render_scene();
};
