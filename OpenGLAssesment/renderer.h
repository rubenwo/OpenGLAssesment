#pragma once
#include "drawable.h"
#include <vector>
#include "Camera.h"
#include <GLFW/glfw3.h>


class renderer
{
private:
	std::vector<drawable*> drawables_;
	GLFWwindow* window;
	Camera camera_;

public:
	renderer() = default;
	renderer(GLFWwindow* window, Camera& camera);
	~renderer() = default;

	void add_drawable(drawable* d);
	void set_camera(Camera& camera);
	void render_scene();
};
