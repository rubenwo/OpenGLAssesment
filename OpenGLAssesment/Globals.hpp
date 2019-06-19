#pragma once
#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#define APPLICATION_NAME "Solar System"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

// Status codes
#define GLUT_INIT_FAILED 1
#define OPENGL_INIT_FAILED 2

typedef unsigned char Key;

struct Color4
{
	float r, g, b, a;

	Color4(float r, float g, float b, float a) : r(r), g(g), b(b), a(a)
	{
	}
};

inline float random(int low, int high)
{
	if (low > high) return high;
	return low + (rand() % (high - low + 1));
}
#endif
