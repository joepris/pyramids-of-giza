#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <cmath>

class RandomMode
{
public:
	RandomMode();
	RandomMode(GLfloat cv, GLfloat mv, GLfloat st, bool sp = false);
	GLfloat genCurrentValue();
	void keyboardControl(bool* kkeys, GLfloat deltaTime);
	void getSpaceValue(bool spacePressed) { isSpacePressed = spacePressed; }
	~RandomMode();

private:
	GLfloat curVal, maxValue, step;
	bool kkeys[512];
	bool direction, spinn;
	bool isSpacePressed = false;
	GLfloat toRadian = 3.141592654f / 180.0f;

};

