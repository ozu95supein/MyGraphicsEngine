#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

//const int for the window dimensions
const unsigned int window_width = 1600;
const unsigned int window_height = 900;



int main ()
{
	//Initialize GLFW
	glfwInit();
	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Create a GLFWwindow object with a width and height and a name, Fullscreen, 
	GLFWwindow* window = glfwCreateWindow(window_width, window_height, "MyGraphicsEngine", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context so we can use it
	glfwMakeContextCurrent(window);
	//load configurations for opengl
	gladLoadGL();
	//Set viewport and background clear color
	glViewport(0, 0, window_width, window_height);
	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	//MAIN WHILE LOOP
	while (!glfwWindowShouldClose(window))
	{
		//Window Events
		glfwPollEvents();
	}

	//delete window and unload glfw
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}