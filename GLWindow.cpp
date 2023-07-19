#include "GLWindow.h"



GLWindow::GLWindow()
{
	width = 2000;
	height = 2000;
}

GLWindow::GLWindow(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
}

GLWindow::~GLWindow()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}





int GLWindow::InitGLWindow()
{
	// Initialise GLFW
	if (!glfwInit())  //initializes OpenGL Window System
	{
		printf("GLFW initialisation failed!");
		glfwTerminate(); //terminate due to error
		return 1;
	}

	// Setup GLFW window properties and version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // Major and minor version is 3.X
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  //
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Core Profile means No Backwards Compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 	// Allow Forward Compatbility

	// Create the window
	mainWindow = glfwCreateWindow(width, height, "JoePris Pyramids of Giza", NULL, NULL); // Create Main Window

	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate(); //terminate due to error
		return 1;
	}
	// Get Buffer Size information
	//int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight); //bufferwidth and bufferHeight is system dependent so, load them.
	glfwMakeContextCurrent(mainWindow); // Set mainWindow as context for GLEW
	glewExperimental = GL_TRUE; 	// Allow modern features

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);  //clear resources already allocated
		glfwTerminate();  //terminate due to error
		return 1;
	}

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, bufferWidth, bufferHeight); // Setup the Viewport dimension


	// Handle Keyboard keys 
	glfwSetKeyCallback(mainWindow, handleKeyboardKeys);

	// Handle Mouse Movement
	glfwSetCursorPosCallback(mainWindow, handleMouseMovements);

	// Handle Mouse Scrollwheel Movement
	glfwSetScrollCallback(mainWindow, handleScrollMovements);

	// Handle Mouse Button Input
	glfwSetMouseButtonCallback(mainWindow, handleMouseClick);

	glfwSetWindowUserPointer(mainWindow, this);



	return 0;
}

//newAddition //keyboard
void GLWindow::handleKeyboardKeys(GLFWwindow* window, int key, int code, int action, int mode)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 512)
	{
		if (action == GLFW_PRESS)
		{
			curWindow->kkeys[key] = true;
			cout << "Keyboard key: (" << key << ") is pressed, mode is: " << mode << "." << endl;
		}
		else if (action == GLFW_RELEASE)
		{
			curWindow->kkeys[key] = false;
			cout << "Keyboard key: (" << key << ") is released" << endl;
		}
		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		{
			//spaceIsPressed = true;
		}
		else if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
		{
			//spaceIsPressed = false;
		}
	}
}

// mouse
void GLWindow::handleMouseMovements(GLFWwindow* window, double xPos, double yPos)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	if (curWindow->initMouse)
	{
		curWindow->prevX = xPos;
		curWindow->prevY = yPos;
		curWindow->initMouse = false;
	}

	curWindow->xChange = xPos - curWindow->prevX;
	curWindow->yChange = curWindow->prevY - yPos;

	curWindow->prevX = xPos;
	curWindow->prevY = yPos;

	cout << "Mouse Movement(" << curWindow->xChange << "," << curWindow->yChange << ")" << endl;
}

// mouse click
void GLWindow::handleMouseClick(GLFWwindow* window, int button, int action, int mode)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS && mode == 2)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
		
	if (button >= 0 && button < 5)
	{
		if (action == GLFW_PRESS)
		{
			curWindow->mbuttons[button] = true;
			if (button == 0)
			{
				cout << "Left Mouse Button Clicked!" << endl;
			}
			if (button == 1)
			{
				cout << "Right Mouse Button Clicked!" << endl;
			}
		}
		else if (action == GLFW_RELEASE)
		{
			curWindow->mbuttons[button] = false;
			if (button == 0)
			{
				cout << "Left Mouse Button Released!" << endl;
			}
			if (button == 1)
			{
				cout << "Right Mouse Button Released!" << endl;
			}
		}
	}
}

// mouse scroll wheel
void GLWindow::handleScrollMovements(GLFWwindow* window, double xoffset, double yoffset)
{
	GLWindow* curWindow = static_cast<GLWindow*>(glfwGetWindowUserPointer(window));

	curWindow->mscroll -= yoffset;
	cout << "Scroll Movement("<<yoffset<<")" << endl;

}

