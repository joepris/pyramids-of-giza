#pragma once
#include <GL\glew.h>
#include <glm/glm.hpp>

class Point_Model
{
public:
	Point_Model();
	void RenderMeshModel();
	//void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		//unsigned int vLength, unsigned int normalOffset);
	~Point_Model();

private:
	GLuint VAO, VBO;
};
