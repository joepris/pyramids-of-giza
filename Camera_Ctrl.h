#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <GLFW\glfw3.h>


class Camera_Ctrl
{
public:
	Camera_Ctrl();
	Camera_Ctrl(glm::vec3 initialPosition, glm::vec3 initialDirection ,glm::vec3 initialUp, GLfloat initialYaw, GLfloat initialPitch, GLfloat initialKeyboardMoveSpeed, GLfloat initialMouseMoveSpeed);
	void keyboardControl(bool* kkeys, GLfloat deltaTime);
	void mouseButtonControl(bool* mbuttons, GLfloat mouseMovementsX, GLfloat mouseMovementsY, bool* kkeys, GLfloat deltaTime);
	//void mouseControl();
	glm::mat4 calculateCameraViewMatrix();
	
	//void getMode(int mode_number) { mode = mode_number; }
	void setCameraPosition(glm::vec3 pos);
	void setCameraDirection(glm::vec3 pos);

	GLfloat getYaw() { return yaw; }
	GLfloat getPitch() { return pitch; }

	void getModelLocation(glm::vec4 newModelPosition) { modelPosition = newModelPosition; }
	void getBuildingTopModelLocation(glm::vec4 modelTopPosition) { buildingTopPosition = modelTopPosition; }
	void getCenterModelLocation(glm::vec4 centerModel) { centerModelPosition = centerModel; }
	void getCenterGroundLocation(glm::vec4 centerGround) { centerGroundPosition = centerGround; }
	void getObjectLocation(glm::vec4 objectLocation) { objectPosition = objectLocation; }
	void getCircumferenceRotatingLocation(glm::vec4 circumferenceLocation) { circumferencePoint = circumferenceLocation; }
	glm::vec3 getCameraPosition();
	glm::vec3 getCameraDirection();

	~Camera_Ctrl();

private:
	glm::vec3 curPos;
	glm::vec3 goFront;
	glm::vec3 lookUp;
	glm::vec3 lookRight;
	glm::vec3 referenceWorldUp;
	int mode;

	GLfloat yaw;
	GLfloat pitch;
	glm::vec3 direction; // set for camera 
	glm::vec3 onTopRotatingObject; // set for camera 
	glm::vec3 onTopCenterObject; // set for camera 
	glm::vec4 modelPosition; //get model position
	glm::vec4 centerModelPosition; //get model position
	glm::vec4 centerGroundPosition; //get model position
	glm::vec4 objectPosition; //get model position
	glm::vec4 buildingTopPosition; //get model position
	glm::vec4 circumferencePoint; //get model position
	GLfloat keyboardMoveSpeed;
	GLfloat mouseMoveSpeeed;

	void updateAllPositions(GLfloat yaw, GLfloat pitch, glm::vec3 direction);
};