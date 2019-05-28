#include "Simulation.hpp"
#include "Camera.hpp"
#include <gl/freeglut.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "SimulationObject.hpp"
#include "SunComponent.hpp"

namespace Simulation
{
	int windowWidth, windowHeight;
	bool keys[256];
	Camera camera;
	SimulationObject* sun;

	void loadContent()
	{
		ZeroMemory(keys, sizeof keys);
		camera = Camera(0, -4, 0, 0, 0, 0);

		sun = new SimulationObject();
		sun->position = Vec3f(0, 0, -1);
		sun->addComponent(new SunComponent());
	}

	void update(float deltaTime)
	{
	}

	void draw()
	{
		glRotatef(camera.rotX, 1, 0, 0);
		glRotatef(camera.rotY, 0, 1, 0);
		glRotatef(camera.rotZ, 0, 0, 1);
		glTranslatef(camera.posX, camera.posZ, camera.posY);


		sun->draw();
	}

	void onKey(Key key)
	{
		keys[key] = true;
	}

	void onKeyUp(Key key)
	{
		keys[key] = false;

		switch (key)
		{
		case VK_ESCAPE:
			glutLeaveMainLoop();
			break;
		case GLUT_KEY_UP:
			camera.posZ -= 0.025f;
			break;
		case GLUT_KEY_DOWN:
			camera.posZ += 0.025f;
			break;
		default:
			break;
		}
	}

	void onMouseMove(int x, int y)
	{
	}

	void onResize(int w, int h)
	{
		windowWidth = w;
		windowHeight = h;
	}

	void onClose()
	{
		std::cout << "Cleaning up game\n";

		std::cout << "Closing game.\n";
	}

	void move(float angle, float fac)
	{
		camera.posX += (float)cos((camera.rotY + angle) / 180 * M_PI) * fac;
		camera.posY += (float)sin((camera.rotY + angle) / 180 * M_PI) * fac;
	}
}
