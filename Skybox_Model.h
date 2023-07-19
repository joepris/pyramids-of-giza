#pragma once
#include <GL\glew.h>
#include<glm/glm.hpp>
class Skybox_Model
{
public:
	Skybox_Model();
	void RenderMeshModel();
	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);
	~Skybox_Model();

private:
	GLuint VAO, VBO;

};



