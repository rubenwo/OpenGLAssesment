#pragma once
#include "drawable.h"
#include <GL/glew.h>

class Sun : public drawable
{
private:

	GLuint vertexbuffer;
	GLuint colorbuffer;
	GLuint programID;

public:
	Sun();
	~Sun();

	void draw() const override;
};
