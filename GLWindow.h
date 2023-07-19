#pragma once
#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include<iostream>

using namespace std;

class GLWindow
{
public:
	GLWindow();
	GLWindow(GLint windowWidth, GLint windowHeight);
	int InitGLWindow();
	GLint getBufferWidth() { return bufferWidth; }
	GLint getBufferHeight() { return bufferHeight; }
	bool isWindowClosed() { return glfwWindowShouldClose(mainWindow); }
	void swapBuffers() { glUseProgram(0); glfwSwapBuffers(mainWindow); }
	static void handleKeyboardKeys(GLFWwindow* window, int key, int code, int action, int get_mode);
	static void handleMouseMovements(GLFWwindow* window, double xPos, double yPos);
	static void handleMouseClick(GLFWwindow* window, int button, int action, int get_mode);
	static void handleScrollMovements(GLFWwindow* window, double xoffset, double yoffset);
	bool* getsKeybordKeys() { return kkeys; }
	bool* getMouseButtons() { return mbuttons; }
	GLfloat getMouseMovementsX() { return xChange; }
	GLfloat getMouseMovementsY() { return yChange; }
	GLfloat getScrollInput() { return mscroll; }
	//static bool getSpaceValue() { return spaceIsPressed; }
	void setScrollInput(GLfloat newScroll) { mscroll = newScroll; }
	void setMouseMovement(GLfloat newMouseMovement) { xChange = newMouseMovement, yChange = newMouseMovement; }
	~GLWindow();
private:
	GLFWwindow* mainWindow;
	GLint width, height;
	GLint bufferWidth, bufferHeight;

	//NewAddition
	
	bool kkeys[512];
	bool mbuttons[5]; // I set 5 keys because my mouse has 5 buttons (left click, right click, middle click, button 4 (at the side of my mouse), button 5(also at the side)
					  // I might use these keys in the future for fun
	GLfloat mscroll;
	//static bool spaceIsPressed; // added for stopping the object movement
	//NewAdditionForMouse
	bool initMouse = true;
	GLfloat prevX;
	GLfloat prevY;
	GLfloat xChange;
	GLfloat yChange;
	GLfloat fov;
};

