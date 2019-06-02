#pragma once
#include <string>
#include <vector>

class Skybox
{
public:
	Skybox();
	~Skybox();

	unsigned int load_cubemap(std::vector<std::string> faces);

	const char* getVertextShaderSource()
	{
		return "#version 330 core"
			"	layout(location = 0) in vec3 aPos;\n"
			"out vec3 TexCoords;\n"
			"uniform mat4 projection;\n"
			"uniform mat4 view;\n"
			"void main()\n"
			"{\n"
			"TexCoords = aPos;\n"
			"gl_Position = projection * view * vec4(aPos, 1.0);\n"
			"}\n\0";
	}

	const char* getFragmentShaderSource()
	{
		return "#version 330 core\n"
			"out vec4 FragColor;\n"
			"in vec3 TexCoords;\n"
			"uniform samplerCube skybox;\n"
			"void main()\n"
			"{\n"
			"   FragColor = texture(skybox, TexCoords);\n"
			"}\n\0";
	}
};
