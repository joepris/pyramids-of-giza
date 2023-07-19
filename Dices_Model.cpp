#include "Dices_Model.h"
#include <ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"


Dices_Model::Dices_Model()
{

	GLfloat vertices[] = {




		-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.67f, 0.0f, 0.0f, 0.0f,	//v5 
		 1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.25f, 0.33f, 0.0f, 0.0f, 0.0f,	//v2 
		-1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.25f, 0.67f, 0.0f, 0.0f, 0.0f,	//v1 
																						//bottom (1)
		1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.25f, 0.33f, 0.0f, 0.0f, 0.0f,	//v2
		-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.67f, 0.0f, 0.0f, 0.0f,	//v5 
		1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.33f, 0.0f, 0.0f, 0.0f,	//v6 

		-1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.25f, 0.67f, 0.0f, 0.0f, 0.0f,	//v1
		1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.33f, 0.0f, 0.0f, 0.0f,	//v3
		-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.67f, 0.0f, 0.0f, 0.0f,	//V0
																						//front (2)
		1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.33f, 0.0f, 0.0f, 0.0f,	//v3
		-1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.25f, 0.67f, 0.0f, 0.0f, 0.0f,	//v1
		1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.25f, 0.33f, 0.0f, 0.0f, 0.0f,	//v2

		1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.33f, 0.0f, 0.0f, 0.0f,	//v7
		-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.66f, 0.0f, 0.0f, 0.0f,	//v4
		-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.67f, 0.0f, 0.0f, 0.0f,	//V0
																						//top (6)
		1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.33f, 0.0f, 0.0f, 0.0f,	//v7
		-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.67f, 0.0f, 0.0f, 0.0f,	//V0
		1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.33f, 0.0f, 0.0f, 0.0f,	//v3

		1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.33f, 0.0f, 0.0f, 0.0f,	//v7
		-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.67f, 0.0f, 0.0f, 0.0f,	//v5
		-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.67f, 0.0f, 0.0f, 0.0f,	//v4
																						//back (5)
		-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.67f, 0.0f, 0.0f, 0.0f,	//v5
		1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.33f, 0.0f, 0.0f, 0.0f,	//v7
		1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.33f, 0.0f, 0.0f, 0.0f,	//v6
		
		1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f,	//v2 
		1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.33f, 0.0f, 0.0f, 0.0f,	//v7 
		1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.33f, 0.0f, 0.0f, 0.0f,	//v3 
																						//right (3)
		1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f,	//v2
		1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.0f, 0.0f, 0.0f, 0.0f,	//v6
		1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.33f, 0.0f, 0.0f, 0.0f,	//v7

		-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.67f, 0.0f, 0.0f, 0.0f,	//V0
		-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 0.67f, 0.0f, 0.0f, 0.0f,	//v4
		-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 1.0f, 0.0f, 0.0f, 0.0f,	//v5
																						//left (4)
		-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.67f, 0.0f, 0.0f, 0.0f,	//V0
		-1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.75f, 1.0f, 0.0f, 0.0f, 0.0f,	//v5
		-1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f	//v1
	};

	calcAverageNormals(NULL, 0, vertices, 11 * 36, 11, 8); //size of vertex data, offset

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 11, 0);  //total values in a point
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 11, (void*)(sizeof(vertices[0]) * 3));  //total values in a point
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 11, (void*)(sizeof(vertices[0]) * 6));  //total values in a point
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 11, (void*)(sizeof(vertices[0]) * 8));  //total values in a point
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

//Replace this code with the correct Normal Function
void Dices_Model::calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	if (indiceCount != 0)
	{
		for (int i = 0; i < indiceCount; i += 3)
		{
			unsigned int in0 = indices[i] * vLength;
			unsigned int in1 = indices[i + 1] * vLength;
			unsigned int in2 = indices[i + 2] * vLength;
			glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
			glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
			glm::vec3 normal = glm::cross(v2, v1);
			normal = glm::normalize(normal);

			in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
			vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
			vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
			vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
		}

		for (int i = 0; i < verticeCount / vLength; i++)
		{
			unsigned int nOffset = i * vLength + normalOffset;
			glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
			vec = glm::normalize(vec);
			vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
		}
	}
	else {


		for (int i = 0; i < verticeCount; i += 3 * vLength)
		{
			unsigned int in0 = i;
			unsigned int in1 = i + vLength;
			unsigned int in2 = i + 2 * vLength;
			glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
			glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
			glm::vec3 normal = glm::cross(v2, v1);
			normal = glm::normalize(normal);

			in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
			vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
			vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
			vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
		}

		for (int i = 0; i < verticeCount / vLength; i++)
		{
			unsigned int nOffset = i * vLength + normalOffset;
			glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
			vec = glm::normalize(vec);
			vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
		}

	}
}

void Dices_Model::RenderMeshModel()
{
	glBindVertexArray(VAO);

	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(4.0f,  5.0f, -5.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -5.3f),
		glm::vec3(5.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(6.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	for (unsigned int i = 0; i < 10; i++)
	{

		Shader* myShader = new Shader();
		glm::mat4 model = glm::mat4(1.0f);

		model = glm::translate(model, cubePositions[i]);
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::translate(model, glm::vec3(0.0, 10.0, -20.0f));
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	glBindVertexArray(0);
}

Dices_Model::~Dices_Model()
{
	if (VBO != 0)
	{
		glDeleteBuffers(1, &VBO);
		VBO = 0;
	}

	if (VAO != 0)
	{
		glDeleteVertexArrays(1, &VAO);
		VAO = 0;
	}

}
