#pragma once

#include"Camera.h"

class InputManager
{
public:
	InputManager(GLFWwindow* window, Camera * cam);
	~InputManager();
	//List of all currently available Input Functions
	void ReceiveInputs();

	void Input_Press_W();
	void Input_Press_A();
	void Input_Press_S();
	void Input_Press_D();
	void Input_Press_SPACE();
	void Input_Press_LCTRL();
	void Input_Press_LSHIFT();
	void Input_Release_LSHIFT();
	void Input_Press_MOUSE_LEFT();
	void Input_Release_MOUST_LEFT();

private:
	GLFWwindow* mCurrentWindow;
	Camera* mCurrentCamera;		
};