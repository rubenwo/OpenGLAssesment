#pragma once
class Camera
{
private:
	float rot_x, rot_y, rot_z, pos_x, pos_y, pos_z;
public:
	Camera() = default;
	~Camera() = default;

	void rotate(float rot_x, float rot_y, float rot_z)
	{
		this->rot_x = rot_x;
		this->rot_y = rot_y;
		this->rot_z = rot_z;
	}

	void move(float pos_x, float pos_y, float pos_z)
	{
		this->pos_x = pos_x;
		this->pos_y = pos_y;
		this->pos_z = pos_z;
	}

	void applyTransform()
	{
	}
};
