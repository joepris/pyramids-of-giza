#pragma once
#include <GL\glew.h>
#include <glm/glm.hpp>

class Pyramid
{
public:
	Pyramid();
	void RenderMeshModel();
	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);
	~Pyramid();

private:
	GLuint VAO, VBO;
};
