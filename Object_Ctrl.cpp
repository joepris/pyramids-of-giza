#include "Object_Ctrl.h"
#include "PointLight.h"
#include "RandomMode.h"

Object_Ctrl::Object_Ctrl()
{
}

Object_Ctrl::Object_Ctrl(glm::mat4 initialMatrix, GLfloat initialKeyboardMoveSpeed, GLfloat initalMouseMoveSpeed)
{
	mouseMoveSpeeed = initalMouseMoveSpeed;
	keyboardMoveSpeed = initialKeyboardMoveSpeed;

}

void Object_Ctrl::mouseButtonControl(bool* mbuttons, GLfloat mouseMovementsX, GLfloat mouseMovementsY, bool* kkeys, GLfloat deltaTime)
{
	GLfloat speed = keyboardMoveSpeed * deltaTime;
	
}

void Object_Ctrl::keyboardControl(bool* kkeys, GLfloat deltaTime)
{
	GLfloat speed = keyboardMoveSpeed * deltaTime;
	RandomMode* rotate = new RandomMode(0, 2 * 3.14159, 0.004, true);
	if(kkeys[GLFW_KEY_R]) // move everything in z direction (negative)
	{
		modelXWing = glm::translate(modelXWing, glm::vec3(0.0f, 0.0f, -0.2f));
		XWingPoint = glm::translate(modelXWing, glm::vec3(0.0f, 0.0f, -0.2f));
	}
	if (kkeys[GLFW_KEY_E]) // move everything in z direction (positive)
	{
		modelXWing = glm::translate(modelXWing, glm::vec3(0.0f, 0.0f, 0.2f));
		XWingPoint = glm::translate(modelXWing, glm::vec3(0.0f, 0.0f, 0.2f));
	}
	if (kkeys[GLFW_KEY_F]) // move everything in x direction (negative)
	{
		modelXWing = glm::translate(modelXWing, glm::vec3(-0.2f, 0.0f, 0.0f));
		XWingPoint = glm::translate(modelXWing, glm::vec3(-0.2f, 0.0f, 0.0f));
	}
	if (kkeys[GLFW_KEY_G]) // move everything in x direction (positive)
	{
		modelXWing = glm::translate(modelXWing, glm::vec3(0.2f, 0.0f, 0.0f));
		XWingPoint = glm::translate(modelXWing, glm::vec3(0.2f, 0.0f, 0.0f));
	}
	if (kkeys[GLFW_KEY_0]) // Bring everything back to normal.
	{
		modelXWing = glm::mat4(((1.0f,0.0f,0.0f,0.0f),(0.0f, 1.0f, 0.0f, 0.0f),(0.0f, 0.0f, 1.0f, 0.0f),(0.0f, 0.0f, 0.0f, 1.0f)));
		XWingPoint = glm::mat4(((1.0f, 0.0f, 0.0f, 0.0f), (0.0f, 1.0f, 0.0f, 0.0f), (0.0f, 0.0f, 1.0f, 0.0f), (0.0f, 0.0f, 0.0f, 1.0f)));
	}

}

Object_Ctrl::~Object_Ctrl()
{
}