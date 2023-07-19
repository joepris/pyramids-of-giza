#define STB_IMAGE_IMPLEMENTATION

#pragma region imports/includes
#include <iostream> //Standard Header Files
#include <conio.h>
#include <iomanip>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <assimp/Importer.hpp> 
#include "glm/ext.hpp"

//Our Own Custom Class Headers
#include "MeshModel.h"   
#include "GLWindow.h"
#include "randomMode.h"
#include "Camera_Ctrl.h"
#include "Light.h"
#include "Shader.h"
#include "Model2D.h"
#include "Dice_Model.h"
#include "TextureMapping.h"
#include "MaterialProperty.h"
#include "Rectangle2DModel.h"
#include "Point_Model.h"
#include "Dices_Model.h"
#include "Building_Model.h"
#include "ImportedModel.h"
#include "Pyramid.h"
#include "Skybox_Model.h"
#include "Object_Ctrl.h"
#pragma endregion

using namespace std;

//void lookInsideMatrix(glm::mat4 model)
//{
//	float matrix[16] = { 0 };
//	memcpy(matrix, glm::value_ptr(model), sizeof(model));
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << fixed << setprecision(2) << setw(5) << matrix[i * 4 + j] << " ";
//		}
//		cout << endl;
//	}
//	//lookInsideMatrix(model);
//	_getch();
//	//requires headerfiles
//	//#include<conio.h>
//	//#include <iomanip>
//}
//
//void myNewObject(Shader* myShader, MeshModel* myShape, glm::mat4 refModel)
//{
//	glm::mat4 model;  //Holds OpenGL Transformation Matrix
//	glm::mat4 model2;
//	model = refModel;
//	model2 = refModel;
//	
//	model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.25f));  //initial scaling
//	model = glm::translate(model, glm::vec3(0.0, -1.0, 0.0f)); //translation
//	glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model));
//	myShape->RenderMeshModel();  //object-01
//
//
//	model2 = glm::scale(model2, glm::vec3(0.25f, 0.25f, 0.25f));  //initial scaling
//	model2 = glm::rotate(model2, 3.141592654f, glm::vec3(0.0f, 0.0f, 1.0f));
//	model2 = glm::translate(model2, glm::vec3(0.0, -1.0, 0.0f)); //translation
//	glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(model2));
//	myShape->RenderMeshModel();  //object-01
//}

int main()
{
	Assimp::Importer a;
	GLWindow myWindow = GLWindow(1000, 1000);
	bool isSpacePressed = false;
	bool* kkeys[512];
	myWindow.InitGLWindow();
	Shader* myShader = new Shader();

	#pragma region LoadModels
		Point_Model* myPoint = new Point_Model();
		Dice_Model* myDice = new Dice_Model();
		Dices_Model* myDices = new Dices_Model();
		Rectangle2DModel* Field = new Rectangle2DModel();
		Building_Model* Building = new Building_Model();
		Pyramid* myPyramid = new Pyramid();
		Skybox_Model* mySkyBox = new Skybox_Model();
		ImportedModel* XWingModel = new ImportedModel();
		ImportedModel* DeadTreeModel = new ImportedModel();
		ImportedModel* Tree = new ImportedModel();
		ImportedModel* ForeignPlanet = new ImportedModel();
		ForeignPlanet->LoadModel("3DModels/Mars.obj");
		XWingModel->LoadModel("3DModels/x-wing.obj");
		DeadTreeModel->LoadModel("3DModels/DeadTree.obj");
		Tree->LoadModel("3DModels/tree.obj");
	#pragma endregion

	#pragma region Light Settings
		DirectionalLight ambientDiffuseLight = DirectionalLight(1.0f, 1.0f, 1.0f, 0.6f, 0.4f, 0.0f, -1.0f, 0.0f); //color+ambient intensity
		PointLight pointLights[MAX_POINT_LIGHTS];
		unsigned int pointLightCount = 0;
	
		pointLights[0] = PointLight(1.0f, 1.0f, 1.0f,
			0.5f, 3.6f,
			5.0f, 0.0f, -10.0f,
			0.3f, 0.3f, 0.3f);
		pointLightCount++;
	
		pointLights[1] = PointLight(1.0f, 0.0f, 0.0f,
			0.5f, 3.6f,
			3.0f, -1.0f, -20.0f, // location of medium large pyramid
			0.3f, 0.2f, 0.1f);
		pointLightCount++;
	
		pointLights[2] = PointLight(0.0f, 1.0f, 0.0f, // color
			0.5f, 3.6f,	//ambient intensity and Diffuse intensity
			9.0f, -1.0f, -14.0f, //Location of largest pyramid
			0.1f, 0.2f, 0.3f); // con, lin, exp
		pointLightCount++;

		pointLights[3] = PointLight(0.0f, 0.0f, 1.0f, // color
			0.5f, 3.6f,	//ambient intensity and Diffuse intensity
			15.0f, -1.0f, -8.0f, //Location smallest large pyramid
			0.1f, 0.2f, 0.3f); // con, lin, exp
		pointLightCount++;
	#pragma endregion
	
	#pragma region LoadTextures
		
		TextureMapping BrickPatternTexture = TextureMapping((char*)"Textures/Brick.png");
		BrickPatternTexture.LoadTextureImage();
		TextureMapping WallPatternTexture = TextureMapping((char*)"Textures/Wall.jpg");
		WallPatternTexture.LoadTextureImage();
		TextureMapping PyramidTexture = TextureMapping((char*)"Textures/Pyramid_Texture.jpg");
		PyramidTexture.LoadTextureImage();
		TextureMapping PyramidTexture2 = TextureMapping((char*)"Textures/Pyramid_Texture2.jpg");
		PyramidTexture2.LoadTextureImage();
		TextureMapping RockPatternTexture = TextureMapping((char*)"Textures/Rock.jpg");
		RockPatternTexture.LoadTextureImage();
		//TextureMapping FieldTexture = TextureMapping((char*)"Textures/field.jpg");
		//FieldTexture.LoadTextureImage();
		TextureMapping TreeTexture = TextureMapping((char*)"Textures/BarkPine0009_1_S.jpg");
		TreeTexture.LoadTextureImage();
		
		TextureMapping GlassBuildingTexture2 = TextureMapping((char*)"Textures/Glass_building_texture2.jpg");
		GlassBuildingTexture2.LoadTextureImage();
		TextureMapping GlassBuildingTexture1 = TextureMapping((char*)"Textures/Glass_building_texture.jpg");
		GlassBuildingTexture1.LoadTextureImage();
		
		TextureMapping RooftopBuilding = TextureMapping((char*)"Textures/WoodTile.jpg");
		RooftopBuilding.LoadTextureImage();
		TextureMapping Skybox = TextureMapping((char*)"Textures/sky.png");
		Skybox.LoadTextureImage();
		TextureMapping SunTexture = TextureMapping((char*)"Textures/SunTexture.jpg");
		SunTexture.LoadTextureImage();
		//TextureMapping CityBlock = TextureMapping((char*)"Textures/CityBlock_Texture.jpg");
		//CityBlock.LoadTextureImage();
		MaterialProperty shinyObject = MaterialProperty(1.8f, 32);
		MaterialProperty dullObject = MaterialProperty(0.1f, 1);
		//TextureMapping RooftopBuildingTexture = TextureMapping((char*)"Textures/Roof_Building_Texture.jpg");
		TextureMapping DiceTexture = TextureMapping((char*)"Textures/Dice4.png");
		TextureMapping DicesTexture = TextureMapping((char*)"Textures/Dice4.png");
		
		DiceTexture.LoadTextureImage();
		
		DicesTexture.LoadTextureImage();
		
		//TextureMapping BirdTexture = TextureMapping((char*)"Textures/Bird.jpg");
		//BirdTexture.LoadTextureImage();
		
		TextureMapping BrownFieldTexture = TextureMapping((char*)"Textures/brown-field.jpg");
		BrownFieldTexture.LoadTextureImage();
		TextureMapping SandTexture = TextureMapping((char*)"Textures/Desert_Sand_Texture.jpg");
		SandTexture.LoadTextureImage();
		
	#pragma endregion

	#pragma region RandomMode & Math
		GLfloat initialSpeed = 0.004;
		RandomMode* xMovement = new RandomMode(0, 1, 0.001, true);
		RandomMode* yMovement = new RandomMode(0, 1, 0.003); 
		RandomMode* rotate = new RandomMode(0, 2 * 3.14159, 0.004, true);
		RandomMode* rotatePlanet = new RandomMode(0, 2 * 3.14159, 0.002, true);
		RandomMode* rotate2 = new RandomMode(0, 2 * 3.14159, 0.001, true);
		RandomMode* rotate3 = new RandomMode(0, 2 * 3.14159, 0.01, true);
		RandomMode* rotateXWing = new RandomMode(0, 2 * 3.14159, initialSpeed, true);
		//variable for degree to radian
		GLfloat toRadian = 3.141592654 / 180.0f;

		GLfloat deltaTime, prevTime;
		deltaTime = prevTime = 0;
		GLfloat fov = 0.0f;
	#pragma endregion
	Object_Ctrl myObject = Object_Ctrl(glm::mat4(0.0f), 0.02f, 0.05f);
	Camera_Ctrl myCamera = Camera_Ctrl(glm::vec3(-10.0f, -0.5f, -21), glm::vec3(0.934131f, 0.127065f, 0.333548f), glm::vec3(0.0f, 1.0f, 0.0f), 7.0f, 5.8f, 0.02f, 0.05f);
	//set speed to 0.02f from 0.002f for faster movement because my pc is slower
	//yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.

	while (!myWindow.isWindowClosed()) 	// Loop until main window is closed
	{
		myShader->UseGpu();

	#pragma region Light
		myShader->SetDirectionalLight(&ambientDiffuseLight);
		myShader->SetPointLights(pointLights, pointLightCount);
		ambientDiffuseLight.UseLight(myShader->GetAmbientIntensity(), myShader->GetColour(), myShader->GetDiffuseIntensity(), myShader->GetDirection());
	#pragma endregion

	// To move the camera, just hold shift and move the mouse. I had to change it for the assignment because left click is used differently here
	// I dont want to leave it in a loop because of the limit of the size of window screen.

	#pragma region UserControls
		// Get/set/control user input events
		GLfloat currentTime = glfwGetTime();
		deltaTime = currentTime - prevTime;
		prevTime = currentTime;
		//glfwPollEvents(); 	
		rotatePlanet->keyboardControl(myWindow.getsKeybordKeys(), deltaTime);
		rotateXWing->keyboardControl(myWindow.getsKeybordKeys(), deltaTime);
		myCamera.keyboardControl(myWindow.getsKeybordKeys(), deltaTime);
		myCamera.mouseButtonControl(myWindow.getMouseButtons(), myWindow.getMouseMovementsX(), myWindow.getMouseMovementsY(), myWindow.getsKeybordKeys(), deltaTime);
		myObject.keyboardControl(myWindow.getsKeybordKeys(), deltaTime);
		myObject.mouseButtonControl(myWindow.getMouseButtons(), myWindow.getMouseMovementsX(), myWindow.getMouseMovementsY(), myWindow.getsKeybordKeys(), deltaTime);
		myWindow.setMouseMovement(0.0f); // added this because camera will continue to pan in the direction of mousemovement if not set back to 0
		//GLfloat mouseInput = myCamera.mouseControl(myWindow.getMouseMovements())
		
		GLfloat newValue = myWindow.getScrollInput();
		if (newValue != 0.0f) {
			fov += newValue;
			if (fov <= -40.0f) 
			{
				fov = -40.0f; // -40.0f is the limit to reach lower limit of 5.0f
			} 
			if (fov >= 44.0f)
			{
				fov = 44.0f; // 44.0f is the limit to reach upper limit of 89.0f
			}
			//cout << "Scroll Movement(" << fov << ")" << endl;
			myWindow.setScrollInput(0.0f); //to remove infinite scroll
			std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;	
			std::cout << glm::to_string(myCamera.getCameraDirection()) << std::endl;
			std::cout << myCamera.getPitch() << std::endl;
			std::cout << myCamera.getYaw() << std::endl;// Use for getting camera postion every scroll
			// use for looking camera directions
		} 

		// Codes used to look for every location
		/*	std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
			std::cout << glm::to_string(myCamera.getCameraDirection()) << std::endl;
			std::cout << myCamera.getPitch() << std::endl;
			std::cout << myCamera.getYaw() << std::endl;*/
	#pragma endregion 
		
	#pragma region Projection and Camera
		glm::mat4 projection = glm::perspective((45.0f + fov) * toRadian, (float)myWindow.getBufferWidth() / (float)myWindow.getBufferHeight(), 0.1f, 100.0f); // 45.0f default value added to the accumulated scroll input value;
		glUniformMatrix4fv(myShader->getUniformProjectionModel(), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(myShader->getCameraViewLoc(), 1, GL_FALSE, glm::value_ptr(myCamera.calculateCameraViewMatrix()));
	#pragma endregion

	#pragma region Points
		// Points are added for different viewing spots
		glm::mat4 centerGroundPoint; // point on bottom/center of Dead Tree
		centerGroundPoint = glm::translate(centerGroundPoint, glm::vec3(0.0f, 0.5f, -11.5f));
		glm::vec4 center_ground_pos = centerGroundPoint * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		myCamera.getCenterGroundLocation(center_ground_pos);
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(centerGroundPoint));
		myPoint->RenderMeshModel();

		glm::mat4 centerModelPoint; // point on top of largest pyramid
		centerModelPoint = glm::translate(centerModelPoint, glm::vec3(9.0f, 4.0f, -14.0f));
		glm::vec4 center_model_pos = centerModelPoint * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		myCamera.getCenterModelLocation(center_model_pos);
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(centerModelPoint));
		myPoint->RenderMeshModel();

		glm::mat4 rotatingModelPoint; // point on top of xWing
		rotatingModelPoint = myObject.setXWingPointMatrix();
		myObject.getXWingPoint(rotatingModelPoint);
		rotatingModelPoint = glm::translate(rotatingModelPoint, glm::vec3(3.0f, 2.0f, -12.0f));
		rotatingModelPoint = glm::rotate(rotatingModelPoint, rotateXWing->genCurrentValue(), glm::vec3(0.0f, -1.0f, 0.0f));
		rotatingModelPoint = glm::translate(rotatingModelPoint, glm::vec3(11.0f, 0.0f, 0.0f));
		glm::vec4 model_pos = rotatingModelPoint * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		myCamera.getModelLocation(model_pos);
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(rotatingModelPoint));
		myPoint->RenderMeshModel();
		pointLights[4] = PointLight(1.0f, 1.0f, 1.0f, // color
			0.5f, 3.6f,	//ambient intensity and Diffuse intensity
			model_pos.x, model_pos.y, model_pos.z, //Location smallest large pyramid
			0.1f, 0.2f, 0.3f); // con, lin, exp
		pointLightCount++;

		glm::mat4 onTopOfBuildingPoint; // point on top of glass viewing building
		onTopOfBuildingPoint = glm::translate(onTopOfBuildingPoint, glm::vec3(-8.9f, 5.2f, -1.73f));
		glm::vec4 top_of_model_pos = onTopOfBuildingPoint * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		myCamera.getBuildingTopModelLocation(top_of_model_pos);
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(onTopOfBuildingPoint));
		myPoint->RenderMeshModel();

		glm::mat4 circumferenceRotatingPoint; // point going around the land
		circumferenceRotatingPoint = glm::translate(circumferenceRotatingPoint, glm::vec3(5.2f, 0.0f, -14.0f));
		circumferenceRotatingPoint = glm::rotate(circumferenceRotatingPoint, rotate->genCurrentValue(), glm::vec3(0.0f, -1.0f, 0.0f));
		circumferenceRotatingPoint = glm::translate(circumferenceRotatingPoint, glm::vec3(0.0f, 0.0f, -12.0f));
		glm::vec4 circumference_rotating_point = circumferenceRotatingPoint * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		myCamera.getCircumferenceRotatingLocation(circumference_rotating_point);
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(onTopOfBuildingPoint));
		myPoint->RenderMeshModel();
	#pragma endregion

	#pragma region Render Models
		/*glm::mat4 dices;
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(dices));
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		DicesTexture.applyTexture();
		myDices->RenderMeshModel();	*/

		glm::mat4 xWing; // render X-Wing
		xWing = myObject.setXWingMatrix();
		myObject.getXWingMatrix(xWing); //space bar spot
		xWing = glm::translate(xWing, glm::vec3(3.0f, 4.0f, -12.0f)); 
		xWing = glm::rotate(xWing, rotateXWing->genCurrentValue(), glm::vec3(0.0f, -1.0f, 0.0f));
		xWing = glm::translate(xWing, glm::vec3(11.0f, 0.0f, 0.0f));
		xWing = glm::scale(xWing, glm::vec3(0.005f, 0.005f, 0.005f));  
		xWing = glm::translate(xWing, glm::vec3(-1400.0172, -108.2528, 1722.1118)); //to bring external model to views
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(xWing));
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		XWingModel->RenderModel();

		
	#pragma region Pyramids
		//First 3 small pyramids
		glm::mat4 smallpyramid1; // render small pyramid 1
		smallpyramid1 = glm::translate(smallpyramid1, glm::vec3(-1.5f, -1.0f, -20.0f));
		smallpyramid1 = glm::scale(smallpyramid1, glm::vec3(0.7f, 0.7f, 0.7f));
		glm::vec4 model_pos_object = smallpyramid1 * glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		myCamera.getObjectLocation(model_pos_object);
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(smallpyramid1));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();

		glm::mat4 smallpyramid2; // render small pyramid 2
		smallpyramid2 = glm::translate(smallpyramid2, glm::vec3(-1.5f, -1.0f, -21.5f));
		smallpyramid2 = glm::scale(smallpyramid2, glm::vec3(0.7f, 0.7f, 0.7f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(smallpyramid2));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();

		glm::mat4 smallpyramid3; // render small pyramid 3
		smallpyramid3 = glm::translate(smallpyramid3, glm::vec3(-1.5f, -1.0f, -23.0f));
		smallpyramid3 = glm::scale(smallpyramid3, glm::vec3(0.7f, 0.7f, 0.7f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(smallpyramid3));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();

		//Second 3 small pyramids
		glm::mat4 smallpyramid4; // render small pyramid 4
		smallpyramid4 = glm::translate(smallpyramid4, glm::vec3(12.5f, -1.0f, -3.5f));
		smallpyramid4 = glm::scale(smallpyramid4, glm::vec3(0.7f, 0.7f, 0.7f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(smallpyramid4));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();

		glm::mat4 smallpyramid5; // render small pyramid 5
		smallpyramid5 = glm::translate(smallpyramid5, glm::vec3(14.0f, -1.0f, -3.5f));
		smallpyramid5 = glm::scale(smallpyramid5, glm::vec3(0.7f, 0.7f, 0.7f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(smallpyramid5));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();

		glm::mat4 smallpyramid6; // render small pyramid 6
		smallpyramid6 = glm::translate(smallpyramid6, glm::vec3(15.5f, -1.0f, -3.5f));
		smallpyramid6 = glm::scale(smallpyramid6, glm::vec3(0.7f, 0.7f, 0.7f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(smallpyramid6));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();

		//3 large pyramids
		glm::mat4 smalllargepyramid; // render smallest Large Pyramid
		smalllargepyramid = glm::translate(smalllargepyramid, glm::vec3(15.0f, -1.0f, -8.0f));
		smalllargepyramid = glm::scale(smalllargepyramid, glm::vec3(1.8f, 2.5f, 1.8f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(smalllargepyramid));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();

		glm::mat4 largestpyramid; // render Largest Pyramid
		largestpyramid = glm::translate(largestpyramid, glm::vec3(9.0f, -1.0f, -14.0f));
		largestpyramid = glm::scale(largestpyramid, glm::vec3(3.0f, 4.2f, 3.0f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(largestpyramid));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();

		glm::mat4 mediumlargepyramid; // render second Large Pyramid
		mediumlargepyramid = glm::translate(mediumlargepyramid, glm::vec3(3.0f, -1.0f, -20.0f));
		mediumlargepyramid = glm::scale(mediumlargepyramid, glm::vec3(2.3f, 2.9f, 2.3f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(mediumlargepyramid));
		PyramidTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		myPyramid->RenderMeshModel();
	#pragma endregion

	#pragma region Building Viewing Tower
		glm::mat4 rooftop1; //rooftop of building to hide glass roof
		rooftop1 = glm::translate(rooftop1, glm::vec3(-8.5f, 4.0f, -2.0f));
		rooftop1 = glm::scale(rooftop1, glm::vec3(0.82f, 0.1f, 0.82f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(rooftop1));
		RooftopBuilding.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Building->RenderMeshModel();

		glm::mat4 building1; //glass building
		building1 = glm::translate(building1, glm::vec3(-8.5f, 1.5f, -2.0f));
		building1 = glm::scale(building1, glm::vec3(0.8f, 2.5f, 0.8f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(building1));
		GlassBuildingTexture1.applyTexture();
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Building->RenderMeshModel();
	#pragma endregion

	#pragma region Environment Models
		glm::mat4 tree5; //external model for plant design
		tree5 = glm::translate(tree5, glm::vec3(15.11f, -1.0f, -20.0f));
		tree5 = glm::scale(tree5, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(tree5));
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Tree->RenderModel();

		glm::mat4 tree4; //external model for plant design
		tree4 = glm::translate(tree4, glm::vec3(-5.0f, -1.0f, -17.3f));
		tree4 = glm::scale(tree4, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(tree4));
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Tree->RenderModel();

		glm::mat4 tree3; //external model for plant design
		tree3 = glm::translate(tree3, glm::vec3(12.5f, -1.0f, -7.5f));
		tree3 = glm::scale(tree3, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(tree3));
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Tree->RenderModel();

		glm::mat4 tree2; //external model for plant design
		tree2 = glm::translate(tree2, glm::vec3(3.5f, -1.0f, -8.5f));
		tree2 = glm::scale(tree2, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(tree2));
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Tree->RenderModel();

		glm::mat4 tree1; //external model for plant design
		tree1 = glm::translate(tree1, glm::vec3(25.5f, -1.0f, -23.5f));
		tree1 = glm::scale(tree1, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(tree1));
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Tree->RenderModel();

		glm::mat4 skybox; // Render Skybox
		skybox = glm::rotate(skybox, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		skybox = glm::scale(skybox, glm::vec3(30.0f, 30.0f, 30.0f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(skybox));
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Skybox.applyTexture();
		mySkyBox->RenderMeshModel();

		glm::mat4 field; // render Field
		field = glm::translate(field, glm::vec3(-10.0, -1.0, 0.0));
		field = glm::rotate(field, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		field = glm::scale(field, glm::vec3(40.0f, 40.0f, 40.0f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(field));
		SandTexture.applyTexture();
		dullObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		Field->RenderMeshModel();

		glm::mat4 foreignPlanet; // Render Foreign Planet
		foreignPlanet = glm::translate(foreignPlanet, glm::vec3(3.0f, 7.0f, -12.0f));
		foreignPlanet = glm::rotate(foreignPlanet, rotatePlanet->genCurrentValue(), glm::vec3(0.0f, 1.0f, 0.0f));
		foreignPlanet = glm::translate(foreignPlanet, glm::vec3(10.0, 0.0, 0.0));
		foreignPlanet = glm::scale(foreignPlanet, glm::vec3(0.05f, 0.05f, 0.05f));
		foreignPlanet = glm::rotate(foreignPlanet, rotate->genCurrentValue(), glm::vec3(0.0f, -1.0f, 0.0f));
		glUniformMatrix4fv(myShader->getUnifromModel(), 1, GL_FALSE, glm::value_ptr(foreignPlanet));
		shinyObject.UseMaterialProperty(myShader->GetSpecularIntensity(), myShader->GetShininess());
		ForeignPlanet->RenderModel();

	#pragma endregion

#pragma endregion

		myWindow.swapBuffers(); //Swap buffers, OpenGL main tains two Buffers, One is displayed, one is getting prepared
	}

	return 0;
}
