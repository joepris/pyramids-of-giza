#include "Camera_Ctrl.h"
#include "PointLight.h"



Camera_Ctrl::Camera_Ctrl()
{
}

Camera_Ctrl::Camera_Ctrl(glm::vec3 initialPosition, glm::vec3 initialDirection, glm::vec3 initialUp, GLfloat initialYaw, GLfloat initialPitch, GLfloat initialKeyboardMoveSpeed, GLfloat initalMouseMoveSpeed)
{
	curPos = initialPosition;
	referenceWorldUp = initialUp;
	yaw = initialYaw;
	pitch = initialPitch;
	goFront = initialDirection;

	mouseMoveSpeeed = initalMouseMoveSpeed;
	keyboardMoveSpeed = initialKeyboardMoveSpeed;
	updateAllPositions(yaw, pitch, goFront);
}

void Camera_Ctrl::updateAllPositions(GLfloat yaw, GLfloat pitch, glm::vec3 setFront)
{
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	goFront = glm::normalize(setFront);

	lookRight = glm::normalize(glm::cross(goFront, referenceWorldUp));
	lookUp = glm::normalize(glm::cross(lookRight, goFront));
}
void Camera_Ctrl::mouseButtonControl(bool* mbuttons, GLfloat mouseMovementsX, GLfloat mouseMovementsY, bool* kkeys, GLfloat deltaTime)
{
	GLfloat speed = keyboardMoveSpeed * deltaTime;
	glm::vec3 backToNormal;
	if (kkeys[GLFW_KEY_LEFT_SHIFT])
	{
		pitch += mouseMovementsY * mouseMoveSpeeed;
		yaw += mouseMovementsX * mouseMoveSpeeed;

		if (pitch > 89.0f) {
			pitch = 89.0f;
		}
		if (pitch < -89.0f) {
			pitch = -89.0f;
		}
	}

	if (mbuttons[GLFW_MOUSE_BUTTON_LEFT])
	{
		//glm::vec4 model_pos = modelPosition * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		direction = (glm::vec3(modelPosition.x, modelPosition.y, modelPosition.z) - getCameraPosition());
		onTopCenterObject = (glm::vec3((centerModelPosition.x) - 1.0f, (centerModelPosition.y), (centerModelPosition.z - 1.0f)));
		setCameraPosition(onTopCenterObject);
	}

	if (mbuttons[GLFW_MOUSE_BUTTON_RIGHT])
	{
		//glm::vec4 model_pos = centerModelPosition * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		direction = (glm::vec3(centerGroundPosition.x, centerGroundPosition.y, centerGroundPosition.z) - getCameraPosition());
		//glm::vec4 RotatingObject = modelPosition * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		onTopRotatingObject = (glm::vec3(modelPosition.x, modelPosition.y+2.0f, modelPosition.z));
		setCameraPosition(onTopRotatingObject);
	}

	updateAllPositions(yaw, pitch, direction);
}

void Camera_Ctrl::keyboardControl(bool* kkeys, GLfloat deltaTime)
{
	GLfloat speed = keyboardMoveSpeed * deltaTime;

	if (kkeys[GLFW_KEY_UP])
	{
		curPos += goFront * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_DOWN])
	{
		curPos -= goFront * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_LEFT])
	{
		curPos -= lookRight * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_RIGHT])
	{
		curPos += lookRight * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_W])
	{
		curPos += goFront * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_S])
	{
		curPos -= goFront * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_A])
	{
		curPos -= lookRight * keyboardMoveSpeed;
	}

	if (kkeys[GLFW_KEY_D])
	{
		curPos += lookRight * keyboardMoveSpeed;
	}
	if (kkeys[GLFW_KEY_F1]) // Original View
	{
		setCameraPosition(glm::vec3(0.0f, 0.0f, 0.0f));
		yaw = -90;
		pitch = 0;
	}
	if (kkeys[GLFW_KEY_F2]) // Front View
	{
		setCameraPosition(glm::vec3(8.60f, 3.0f, 13.5f));
		yaw = -90;
		pitch = 0;
	}
	if (kkeys[GLFW_KEY_F3]) // Top View, Limit Top
	{
		setCameraPosition(glm::vec3(7.76f, 30.0f, -12.0f));
		yaw = -90;
		pitch = -89;
	}
	if (kkeys[GLFW_KEY_F4]) // Side View, Limit Side
	{
		setCameraPosition(glm::vec3(29.7f, -0.666f, -13.8f));
		yaw = -180;
		pitch = 0;
	}
	if (kkeys[GLFW_KEY_I]) //Setting the Camera Position to a designated object
	{
		setCameraPosition(glm::vec3(objectPosition.x, objectPosition.y, objectPosition.z));
	}
	if (kkeys[GLFW_KEY_T]) //Best Viewing Spot, Copying the images from a searched image
	{
		yaw = 11.15;
		pitch = -0.65;
		setCameraPosition(glm::vec3(-10.0f, -0.5f, -21.0f));
	}
	if (kkeys[GLFW_KEY_Y]) //View the X-wing from a ground location near the center
	{
		direction = (glm::vec3(modelPosition.x, modelPosition.y, modelPosition.z) - getCameraPosition());
		setCameraPosition(glm::vec3(3.32f, -0.675f, -7.827f));
	}
	if (kkeys[GLFW_KEY_L]) //View X-Wing while at the top of the building
	{
		direction = (glm::vec3(modelPosition.x, modelPosition.y, modelPosition.z) - getCameraPosition());
		onTopCenterObject = (glm::vec3((centerModelPosition.x) - 1.0f, (centerModelPosition.y), (centerModelPosition.z - 1.0f)));
		setCameraPosition(glm::vec3(buildingTopPosition.x, buildingTopPosition.y, buildingTopPosition.z));
	}
	if (kkeys[GLFW_KEY_M]) //Looking at the Pyramid While revolving around the map
	{
		//direction = (glm::vec3(modelPosition.x, modelPosition.y, modelPosition.z) - getCameraPosition());
		onTopCenterObject = (glm::vec3((centerModelPosition.x) - 1.0f, (centerModelPosition.y), (centerModelPosition.z - 1.0f)));
		setCameraPosition(glm::vec3(circumferencePoint.x, circumferencePoint.y, circumferencePoint.z));
	}
	if (kkeys[GLFW_KEY_K])
	{
		direction = (glm::vec3(circumferencePoint.x, circumferencePoint.y, circumferencePoint.z) - getCameraPosition());
		setCameraPosition(glm::vec3(buildingTopPosition.x, buildingTopPosition.y, buildingTopPosition.z));
	}
}

glm::mat4 Camera_Ctrl::calculateCameraViewMatrix()
{
	return glm::lookAt(curPos, curPos + goFront, lookUp);
}

void Camera_Ctrl::setCameraPosition(glm::vec3 pos)
{
	curPos = pos;
}

void Camera_Ctrl::setCameraDirection(glm::vec3 modelPosition)
{
	goFront = glm::normalize(modelPosition);
}

glm::vec3 Camera_Ctrl::getCameraPosition()
{
	return curPos;
}

glm::vec3 Camera_Ctrl::getCameraDirection()
{
	return glm::normalize(goFront);
}


Camera_Ctrl::~Camera_Ctrl()
{
}












