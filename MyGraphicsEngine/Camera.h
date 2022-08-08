<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
#pragma once
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};
=======
=======
#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

>>>>>>> Camera done, with inputs
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
#include "shaderClass.h"
>>>>>>> .
=======
#include"shaderClass.h"
>>>>>>> Camera done, with inputs

class Camera
{
public:
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
	
	Camera()
	{
		mViewMatrix = mat4(1.0f);
		mProjectionMatrix = mat4(1.0f);
		mCamSpeed = 5.0f;
	}
	~Camera()
	{

	}
	Camera(mat4 V, mat4 P)
	{
		mViewMatrix = V;
		mProjectionMatrix = P;
		mCamSpeed = 5.0f;
	}
	Camera(vec3 eye_pos, vec3 up, vec3 position_to_look_at, float FOV, float aspect, float near, float far, float cam_speed)
	{
		mViewMatrix = lookAt(eye_pos, position_to_look_at, up);
		mProjectionMatrix = perspective(FOV, aspect, near, far);
		mCamSpeed = cam_speed;
	}
	mat4 GetViewMatrix()
	{
		return mViewMatrix;
	}
	void SetViewMatrix(mat4 v)
	{
		mViewMatrix = v;
	}
	mat4 GetProjectionMatrix()
	{
		return mProjectionMatrix;
	}
	void SetProjectionMatrix(mat4 p)
	{
		mProjectionMatrix = p;
	}
	vec3 ExtractCamPosition()
	{
		vec3 result;
		result.x = mViewMatrix[0].w;
		result.y = mViewMatrix[1].w;
		result.z = mViewMatrix[2].w;
		return result;
	}
	vec3 ExtractCamRight()
	{
		vec3 result;
		result.x = mViewMatrix[0].x;
		result.y = mViewMatrix[0].y;
		result.z = mViewMatrix[0].z;
		return result;
	}
	vec3 ExtractCamUp()
	{
		vec3 result;
		result.x = mViewMatrix[1].x;
		result.y = mViewMatrix[1].y;
		result.z = mViewMatrix[1].z;
		return result;
	}
	vec3 ExtractCamDirection()
	{
		vec3 result;
		result.x = mViewMatrix[0].x;
		result.y = mViewMatrix[0].y;
		result.z = mViewMatrix[0].z;
		return result;
	}
	//camera movement controls
	// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction, float deltaTime)
	{
		float velocity = mCamSpeed * deltaTime;
		vec3 Position = ExtractCamPosition();
		if (direction == FORWARD)
		{
			vec3 Front = ExtractCamDirection();
			Position += Front * velocity;
		}
		if (direction == BACKWARD)
		{
			vec3 Front = ExtractCamDirection();
			Position -= Front * velocity;
		}
		if (direction == LEFT)
		{
			vec3 Right = ExtractCamRight();
			Position -= Right * velocity;
		}
		if (direction == RIGHT)
		{
			vec3 Right = ExtractCamRight();
			Position += Right * velocity;
		}
		//modify the last 'column'(opengl is column major) of the view matrix
		mat4 v2 = GetViewMatrix();
		v2[0].w = Position.x;
		v2[1].w = Position.y;
		v2[2].w = Position.y;
		SetViewMatrix(v2);
	}
private:
	float mCamSpeed;
	mat4 mViewMatrix;
	mat4 mProjectionMatrix;
=======
=======
	// Stores the main vectors of the camera
>>>>>>> Camera done, with inputs
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	// Prevents the camera from jumping around when first clicking left click
	bool firstClick = true;

	// Stores the width and height of the window
	int width;
	int height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float DefaultCamSpeed = 1.0f;
	float FastCamSpeed = DefaultCamSpeed * 4.0f;
	float DefaultSensitivity = 40.0f;

	float speed = DefaultCamSpeed;
	float sensitivity = DefaultSensitivity;

	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);

	// Updates and exports the camera matrix to the Vertex Shader
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	void Matrix(Shader shader, const char* uniform);
	// Handles camera inputs
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
	void Inputs(GLFWwindow* window);
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369

private:

>>>>>>> .
};
=======
=======
	void Inputs(GLFWwindow* window, float deltaTime);
>>>>>>> Basic Lighting done, we will move on to specular maps
};
#endif
>>>>>>> Camera done, with inputs
