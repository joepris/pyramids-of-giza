#pragma once
#include <GL\glew.h>
#include <glm/glm.hpp>

class Dice_Model
{
public:
	Dice_Model();
	void RenderMeshModel();
	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);
	~Dice_Model();

private:
	GLuint VAO, VBO;
};
