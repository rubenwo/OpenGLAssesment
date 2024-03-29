﻿#include "Simulation.h"
#include "Camera.hpp"
#include "Renderer.h"
#include <GL/glut.h>
#include <ctime>
#include "Planet.h"
#include "Sun.h"
#include "TextureLoader.h"
#include <stack>
#include "Globals.hpp"
#include <iostream>
#include <string>

namespace Simulation
{
	bool one = false;
	static float tx = 0.0;
	static float rotx = 0.0;
	static float worldX = 15.0;
	static float worldY = 0.0;
	static float scaleFactor = 0.6;
	static bool animate = false;
	static float first = 1;
	static float second = 1;
	point stars[500];
	int windowWidth = WINDOW_WIDTH;
	int windowHeight = WINDOW_HEIGHT;

	inline float map(float input, float srcRangeLow, float srcRangeHigh, float dstRangeLow, float dstRangeHigh)
	{
		return dstRangeLow + (input - srcRangeLow) * (dstRangeHigh - dstRangeLow) / (srcRangeHigh - srcRangeLow);
	}

	int globalW, globalH;
	//std::vector<GLuint> textures;
	std::vector<std::string> textures = {
		"sun.bmp", "mercury.bmp", "venus.bmp", "earth.bmp", "mars.bmp", "jupiter.bmp", "saturn.bmp", "uranus.bmp",
		"neptune.bmp", "pluto.bmp"
	};

	void keimeno(const char* str, float size)
	{
		glPushMatrix();
		glScalef(size, size, size);

		for (int i = 0; i < strlen(str); i++)
			glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
		glPopMatrix();
	}

	void RandomCoordinates(point* star)
	{
		int lowest = -1000, highest = 1000;
		int range = (highest - lowest) + 1;
		star->x = lowest + int(range * rand() / (RAND_MAX + 1.0));
		star->y = lowest + int(range * rand() / (RAND_MAX + 1.0));
		star->z = lowest + int(range * rand() / (RAND_MAX + 1.0));
	}

	void DrawStars()
	{
		GLUquadricObj* quadric;
		quadric = gluNewQuadric();
		gluQuadricDrawStyle(quadric, GLU_FILL);
		gluDeleteQuadric(quadric);
		for (int i = 0; i < 500; i++)
		{
			glPushMatrix();
			glTranslatef(stars[i].x, stars[i].y, stars[i].z);
			glColor3f(1, 1, 1);
			gluSphere(quadric, 1, 36, 18);
			glPopMatrix();
		}
	}

	void CreatePlanets(Renderer* renderer, std::string texture)
	{
		std::cout << texture.c_str() << "\n";
		Vec3f p = {float(random(25, 125)), float(random(-5, 5)), float(random(-50, 50))};
		if (random(0, 10) > 3)
			p.x *= -1;

		renderer->add_renderable(new Planet(p, texture, float(rand() % 10)));
	}

	Renderer* renderer;
	camera cam = {0, 0, 0, 0, 0, 0};


	void LoadContent()
	{
		int planet_amt = textures.size() - 1;
		renderer = new Renderer();
		renderer->add_renderable(new Sun(textures[0]));

		for (auto i = 0; i < planet_amt; i++)
		{
			CreatePlanets(renderer, textures[i + 1]);
		}
		//get random cordinates for the stars
		for (int i = 0; i < 500; i++)
			RandomCoordinates(&stars[i]);
		srand(time(0));
		//Parameter handling
		glShadeModel(GL_SMOOTH);

		// polygon rendering mode
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

		// Black background
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void Render()
	{
		//CLEARS FRAME BUFFER ie COLOR BUFFER& DEPTH BUFFER (1.0)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clean up the colour of the window
		// and the depth buffer
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();


		glTranslatef(0, 0, -100);

		if (!animate)
		{
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
			glColor3f(1, 1, 1);
			glTranslatef(-8, 50, 0.0);
			keimeno("Pause", 0.05f);
			glPopMatrix();
		}
		glRotatef(worldX, 1, 0, 0);
		glRotatef(worldY, 0, 1, 0);
		glScalef(scaleFactor, scaleFactor, scaleFactor);


		renderer->draw();

		DrawStars();

		glutSwapBuffers();
	}

	int lastTime = 0;

	void Idle()
	{
		int currentTime = glutGet(GLUT_ELAPSED_TIME);
		float deltaTime = (currentTime - lastTime) / 1000.0f;
		lastTime = currentTime;

		if (animate)
			renderer->update(deltaTime);

		glutPostRedisplay();
	}

	void Reshape(int w, int h)
	{
		// define the visible area of the window ( in pixels )
		if (h == 0) h = 1;
		glViewport(0, 0, w, h);
		globalH = h;
		globalW = w;
		windowHeight = h;
		windowWidth = w;
		// Setup viewing volume
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(60.0, (float)w / (float)h, 1.0, 1000.0);
	}

	void OnMouseActiveMove(int x, int y)
	{
		worldX = y; //scaleFactor * map(x, 0, windowWidth, -1, 1);
		worldY = x; //scaleFactor * map(y, 0, windowWidth, -1, 1);
	}

	void OnMousePassiveMove(int x, int y)
	{
	}

	void OnMouseScroll(int button, int state, int x, int y)
	{
		if (animate)
		{
			if (state > 0)
			{
				scaleFactor += 0.01;
				//glutPostRedisplay();
			}
			else
			{
				if (scaleFactor > 0.08)
				{
					scaleFactor -= 0.01;
					//	glutPostRedisplay();
				}
			}
		}
	}

	void OnKeyPressed(unsigned char key, int x, int y)
	{
		switch (key)
		{
		case 'q': exit(0);
			break;
		case 'w': if (animate) worldX -= 1.0f;
			break;
		case 's': if (animate) worldX += 1.0f;
			break;
		case 'a': if (animate) worldY -= 1.0f;
			break;
		case 'd': if (animate) worldY += 1.0f;
			break;
		case ' ': animate = !animate;;
			break;
		default: break;
		}
		//	glutPostRedisplay();
	}

	void OnSpecialKey(unsigned char key, int x, int y)
	{
	}

	void OnClose()
	{
	}
}
