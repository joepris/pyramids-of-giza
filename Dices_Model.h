#pragma once
#include <GL\glew.h>
#include <glm/glm.hpp>

class Dices_Model
{
public:
	Dices_Model();
	void RenderMeshModel();
	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);
	~Dices_Model();

private:
	GLuint VAO, VBO;
};
