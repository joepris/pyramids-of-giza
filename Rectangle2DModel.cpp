#include "Rectangle2DModel.h"




Rectangle2DModel::Rectangle2DModel()
{
	unsigned int indices[] = {
		0, 2, 1,   //up
		0, 2, 3   //down 

	};

	GLfloat vertices[] = {
		// x      y     z		R	  G    B   u     v
		  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,  //top middle & half behind, point 0 //
		  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 20.0f,  //left bottom, point 1 //
		  1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 20.0f, 20.0f, //right bottom, point 2
		  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 20.0f, 0.0f,	//bottom middle behind, point 3
	};


	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, 0);  //total values in a point
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 3));  //total values in a point
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 8, (void*)(sizeof(vertices[0]) * 6));  //total values in a point
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Rectangle2DModel::RenderMeshModel()
{
	glBindVertexArray(VAO);

	//glDrawArrays(GL_TRIANGLES, 0, 12);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glBindVertexArray(0);
}


Rectangle2DModel::~Rectangle2DModel()
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

	if (IBO != 0)
	{
		glDeleteBuffers(1, &IBO);
		IBO = 0;
	}

}

