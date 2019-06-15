#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "globals.hpp"

void Camera::move(float pos_x, float pos_y, float pos_z)
{
	this->values_.pos_x = pos_x;
	this->values_.pos_y = pos_y;
	this->values_.pos_z = pos_z;
}


void Camera::rotate(float rot_x, float rot_y, float rot_z)
{
	this->values_.rot_x = rot_x;
	this->values_.rot_y = rot_y;
	this->values_.rot_z = rot_z;
}

void Camera::apply_camera()
{
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f,
	                                        100.0f);

	// Or, for an ortho camera :
	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(this->values_.pos_x, this->values_.pos_y, this->values_.pos_z),
		// Camera is at (4,3,3), in World Space
		glm::vec3(this->values_.rot_x, this->values_.rot_y, this->values_.rot_z), // and looks at the origin
		glm::vec3(0, 1, 0) // Head is up (set to 0,-1,0 to look upside-down)
	);

	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around

	// Send our transformation to the currently bound shader, in the "MVP" uniform
	// This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
}
