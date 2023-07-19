#pragma once

#include <GL\glew.h>


class Rectangle2DModel
{

public:
	Rectangle2DModel();
	void RenderMeshModel();
	~Rectangle2DModel();

private:
	GLuint VAO, VBO, IBO;


};

