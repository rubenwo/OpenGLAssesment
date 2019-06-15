#pragma once
#include <GL/glew.h>
#include <GL/gl.h>

struct Camera_Values
{
	float rot_x, rot_y, rot_z, pos_x, pos_y, pos_z;
};


class Camera
{
private:
	Camera_Values values_;
	GLuint MatrixID;
public:
	Camera()
	{
		this->values_ = {1, 2, 0, 1, -1, 0};
	}

	~Camera() = default;

	void rotate(float rot_x, float rot_y, float rot_z);
	void move(float pos_x, float pos_y, float pos_z);

	void apply_camera();
};
