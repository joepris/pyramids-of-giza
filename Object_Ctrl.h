#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <GLFW\glfw3.h>
class Object_Ctrl
{
public:
	Object_Ctrl();
	Object_Ctrl(glm::mat4 initialMatrix, GLfloat initialKeyboardMoveSpeed, GLfloat initalMouseMoveSpeed);
	void keyboardControl(bool* kkeys, GLfloat deltaTime);
	void mouseButtonControl(bool* mbuttons, GLfloat mouseMovementsX, GLfloat mouseMovementsY, bool* kkeys, GLfloat deltaTime);
	void getModelLocation(glm::mat4 newModelMatrix) { modelPosition = newModelMatrix; }
	void getXWingMatrix(glm::mat4 newModelXWingMatrix) { modelXWing = newModelXWingMatrix; }
	void getXWingPoint(glm::mat4 newModelXWingPoint) { XWingPoint = newModelXWingPoint; }
	void getOriginalXWingMatrix(glm::mat4 newModelXWingMatrix) { originalXWingMatrix = newModelXWingMatrix; }
	glm::mat4 setXWingMatrix() { return modelXWing; }
	glm::mat4 setXWingPointMatrix() { return XWingPoint; }
	~Object_Ctrl();

private:
	glm::mat4 modelPosition; //get model matrix
	glm::mat4 modelXWing; //get model matrix
	glm::mat4 XWingPoint;
	glm::mat4 originalXWingMatrix; //get model original matrix
	GLfloat keyboardMoveSpeed;
	GLfloat mouseMoveSpeeed;
};

