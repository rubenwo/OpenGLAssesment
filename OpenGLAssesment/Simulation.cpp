#include "Simulation.hpp"
#include "Camera.hpp"
#include <gl/freeglut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "SimulationObject.hpp"
#include "SunComponent.hpp"
#include "Skybox.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Simulation
{
	int windowWidth, windowHeight;
	bool keys[256];
	Camera camera;
	Skybox* skybox;
	SimulationObject* sun;
	SimulationObject* planet;
	float angle = 0.0;

	std::string loadFile(const char* fname)
	{
		std::ifstream file(fname);
		if (!file.is_open())
		{
			std::cout << "Unable to open file " << fname << std::endl;
			exit(1);
		}

		std::stringstream fileData;
		fileData << file.rdbuf();
		file.close();

		return fileData.str();
	}

	void loadContent()
	{
		ZeroMemory(keys, sizeof keys);
		camera = Camera(0, -4, 0, 0, 0, 0);
		skybox = new Skybox();
		std::vector<std::string> faces;
		{
			"right.jpg",
				"left.jpg",
				"top.jpg",
				"bottom.jpg",
				"front.jpg",
				"back.jpg";
		};
		unsigned int cubemapTexture = skybox->load_cubemap(faces);


		sun = new SimulationObject();
		sun->position = Vec3f(0, 0, -1);
		sun->addComponent(new SunComponent());

		planet = new SimulationObject();
		planet->position = Vec3f(1, 1, -1);
		planet->addComponent(new SunComponent());
	}

	void update(float deltaTime)
	{
		angle += 0.01;
	}

	void draw()
	{
		glRotatef(camera.rotX, 1, 0, 0);
		glRotatef(camera.rotY, 0, 1, 0);
		glRotatef(camera.rotZ, 0, 0, 1);
		glTranslatef(camera.posX, camera.posZ, camera.posY);

		glRotatef(angle, 0, 0, 1);
		sun->draw();
		planet->draw();
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
