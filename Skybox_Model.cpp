#include "Skybox_Model.h"

Skybox_Model::Skybox_Model()
{
	GLfloat vertices[] = {

		//front  //Normal Corrected.

		  -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 1.0f, 0.0f, 0.0f, 0.0f, //v5
		   1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.75f,  0.0f,  0.0f, 0.0f, //v2
		  -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 1.0f,   0.0f,  0.0f, 0.0f, //v1

		  1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.75f,  0.0f,  0.0f, 0.0f,  //v2
		  -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 1.0f,  0.0f,  0.0f, 0.0f, //v5			
		   1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.75f,  0.0f,  0.0f, 0.0f,//v6


		   //right Corrected..

			   1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.75f,  0.0f,  0.0f, 0.0f,//v2
			   1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.5f,  0.0f,  0.0f, 0.0f, //v7
			   1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.5f,   0.0f,  0.0f, 0.0f,//v3

			   1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.75f,  0.0f,  0.0f, 0.0f,//v2
			   1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.75f,  0.0f,  0.0f, 0.0f,//v6
			   1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.5f,   0.0f,  0.0f, 0.0f,//v7


			   //Back Corrected.
				   1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.5f,  0.0f,  0.0f, 0.0f,//v7
				  -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.25f, 0.0f,  0.0f, 0.0f,//v4
				  -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.25f,  0.0f,  0.0f, 0.0f, //V0

				   1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.5f,  0.0f,  0.0f, 0.0f,//v7
				  -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.25f,  0.0f,  0.0f, 0.0f,//V0
				   1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.5f,	  0.0f,  0.0f, 0.0f,//v3

				   //left Corrected..

					  -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.25f,  0.0f,  0.0f, 0.0f, //V0
					  -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.25f,  0.0f,  0.0f, 0.0f,//v4
					  -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.0f, 0.0f,  0.0f, 0.0f,//v5

					  -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.25f,  0.0f,  0.0f, 0.0f,//V0
					  -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.0f,  0.0f,  0.0f, 0.0f, //v5
					  -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.0f,   0.0f,  0.0f, 0.0f,//v1


					  //UP Corrected.
						  -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.25f,  0.0f,  0.0f, 0.0f,//v1
						  1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.5f,	  0.0f,  0.0f, 0.0f,//v3
						  -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.25f,  0.0f,  0.0f, 0.0f,//V0

						  1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.666f, 0.5f,  0.0f,  0.0f, 0.0f,//v3
						  -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.25f,  0.0f,  0.0f, 0.0f,//v1
						  1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f,  0.0f,  0.0f, 0.0f,//v2

						  // Down Corrected
						  1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.5f,  0.0f,  0.0f, 0.0f, //v7
						  -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.25f, 0.0f,  0.0f, 0.0f,	//v5
						  -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.25f, 0.0f,  0.0f, 0.0f,  //v4

						  -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.25f , 0.0f,  0.0f, 0.0f,	//v5
						  1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.333f, 0.5f,  0.0f,  0.0f, 0.0f, //v7
						  1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.5f,  0.0f,  0.0f, 0.0f,//v6

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
void Skybox_Model::calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
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


void Skybox_Model::RenderMeshModel()
{
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glBindVertexArray(0);
}


Skybox_Model::~Skybox_Model()
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


