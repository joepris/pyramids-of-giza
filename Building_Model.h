#pragma once
#include <GL\glew.h>
#include <glm/glm.hpp>

class Building_Model
{
public:
	Building_Model();
	void RenderMeshModel();
	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);
	~Building_Model();

private:
	GLuint VAO, VBO;
};
