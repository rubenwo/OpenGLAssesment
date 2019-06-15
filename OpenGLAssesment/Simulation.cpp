#include "Simulation.h"
#include "Renderer.h"
#include <GL\freeglut.h>
#include "Camera.hpp"
#include "Sun.h"

namespace Simulation
{
	Camera* camera;
	Renderer* renderer;

	void loadContent()
	{
		camera = new Camera();
		renderer = new Renderer();

		ZeroMemory(keys, sizeof keys);
		auto* sun = new Sun();
		auto* earth = new Planet();
		auto* moon = new Moon();

		earth->addMoon(moon);
		sun->addPlanet(earth);

		renderer->addRenderable(sun);
		renderer->addRenderable(sun);
		renderer->addRenderable(sun);
	}

	void update(float deltaTime)
	{
		renderer->update(deltaTime);
	}

	void draw()
	{
		camera->applyTransform();
		renderer->draw();
	}

	void onKey(Key key)
	{
	}

	void onKeyUp(Key key)
	{
	}

	void onMouseMove(int x, int y)
	{
	}

	void onMouseWheel(int wheel, int dir, int x, int y)
	{
	}


	void onResize(int w, int h)
	{
	}

	void onClose()
	{
		delete camera;
		delete renderer;
	}

	void loadTextures()
	{
	}

	int lastTime = 0;

	void idle()
	{
		int currentTime = glutGet(GLUT_ELAPSED_TIME);
		float deltaTime = (currentTime - lastTime) / 1000.0f;

		lastTime = currentTime;
		Simulation::update(deltaTime);

		glutPostRedisplay();
	}
};
