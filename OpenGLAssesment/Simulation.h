#pragma once
#include "Renderer.h"

class Simulation
{
private:
	Renderer renderer_;
public:
	Simulation() = default;
	~Simulation() = default;

	void display_func(void);
	void reshape_func(int width, int height);
	void idle_func(void);
	void mouse_func(int button, int state, int x, int y);
	void mouse_wheel_func(int wheel, int direction, int x, int y);
	void keyboard_func(unsigned char key, int x, int y);
};
