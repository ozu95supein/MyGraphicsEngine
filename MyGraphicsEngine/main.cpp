#include"imgui.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_opengl3.h"

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include "CustomShader.h"		//my custom shader class code is here
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
#include "CustomVBO.h"
#include "CustomVAO.h"
#include "CustomEBO.h"
#include "Camera.h"
=======
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
>>>>>>> Added VBOs, VAOs, EBOs to this branch

//callbacks for input and window events
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, Camera &currentCam);


int WindowWidth = 800;
int WindowHeight = 800;

float deltaTime = 0.0f;  //Gloabal value, time between current frame and last frame
float lastFrame = 0.0f;  //Gloabal value, time of last frame
void UpdateDeltaTime();

glm::vec4 InitialClearColor = { 0.07f, 0.13f, 0.17f, 1.0f };

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
//DEFAULT CAMERA VALUES
/*****************************************************************************/
glm::vec3 default_eye_pos = vec3(0.0f, 0.0f, 5.0f);
glm::vec3 default_up = vec3(0.0f, 1.0f, 0.0f);
glm::vec3 default_position_to_look_at = vec3(0.0f, 0.0f, 0.0f);
float default_FOV = glm::radians(60.0f);
//Aspect is given by window
float default_near = 0.1f;
float default_far = 100.0f;
float default_cam_speed = 5.0f;
/*****************************************************************************/

=======
>>>>>>> Fragment shader and buffer classes modified
// Vertices coordinates
/*****************************************************************************/
=======

// Vertices coordinates
>>>>>>> Added VBOs, VAOs, EBOs to this branch
GLfloat vertices[] =
{ //               COORDINATES                  /     COLORS           //
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
};
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
=======

>>>>>>> Added VBOs, VAOs, EBOs to this branch
// Indices for vertices order
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
/*****************************************************************************/
=======
>>>>>>> Added VBOs, VAOs, EBOs to this branch

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(WindowWidth, WindowHeight, "Oscar's Game Engine", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, WindowWidth, WindowHeight);
	//contruct the camera for the scene
	
	glm::vec3 eye_pos = default_eye_pos;
	glm::vec3 up = default_up;
	glm::vec3 position_to_look_at = default_position_to_look_at;
	float FOV = default_FOV;
	float aspect = (float)WindowWidth / (float)WindowHeight;
	float near = default_near;
	float far = default_far;
	float speed = default_cam_speed;
	//Camera Object
	Camera mainCameraObject(eye_pos, up, position_to_look_at, FOV, aspect, near, far, speed);

	CustomShader myShader("default.vert", "default.frag");
	
	glEnable(GL_DEPTH_TEST);
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369

	//generate vertex array object and binds it
	CustomVAO VAO1;
	VAO1.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	CustomVBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	CustomEBO EBO1(indices, sizeof(indices));
=======
	
	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));
>>>>>>> Added VBOs, VAOs, EBOs to this branch

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Initialize ImGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	// Variables to be changed in the ImGUI window
	bool drawTriangle = true;
	float size = 1.0f;
	float color[4] = { 0.8f, 0.3f, 0.02f, 1.0f };


	myShader.use();
	// Exporting variables to shaders
	myShader.setFloat("size", size);
	myShader.setFloat4("color", color[0], color[1], color[2], color[3]);
	//Matrix Stuff placed here for now
	///////////////////////////////////////////////////////////////////////////
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));
	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
	myShader.setMatrix4("transform", &trans);

	//projection matrix
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	
	glm::mat4 view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = mainCameraObject.GetViewMatrix();
	glm::mat4 projection;
	projection = mainCameraObject.GetProjectionMatrix();

	myShader.setMatrix4("model", &model);
	myShader.setMatrix4("view", &view);
	myShader.setMatrix4("projection", &projection);
	///////////////////////////////////////////////////////////////////////////

	// Specify the color of the background
	glClearColor(InitialClearColor.x, InitialClearColor.y, InitialClearColor.z, InitialClearColor.w);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		//Update the delta time global values
		UpdateDeltaTime();

		//Process Input from the user 
		processInput(window, mainCameraObject);

		//Update camera Matrices in the shader
		view = mainCameraObject.GetViewMatrix();
		projection = mainCameraObject.GetProjectionMatrix();
		myShader.setMatrix4("view", &view);
		myShader.setMatrix4("projection", &projection);

		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Tell OpenGL a new frame is about to begin
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();


		model = glm::rotate(model, glm::radians(0.1f), glm::vec3(0.0f, 0.0f, 1.0f));
		myShader.setMatrix4("model", &model);

		// Tell OpenGL which Shader Program we want to use
		myShader.use();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Only draw the triangle if the ImGUI checkbox is ticked
		if (drawTriangle)
			// Draw the triangle using the GL_TRIANGLES primitive
			glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		// ImGUI window creation
		ImGui::Begin("My name is window, ImGUI window");
		// Text that appears in the window
		ImGui::Text("Hello there adventurer!");
		// Checkbox that appears in the window
		ImGui::Checkbox("Draw Triangle", &drawTriangle);
		// Slider that appears in the window
		ImGui::SliderFloat("Size", &size, 0.5f, 2.0f);
		// Fancy color editor that appears in the window
		ImGui::ColorEdit4("Color", color);
		// Ends the window
		ImGui::End();

		myShader.use();
		// Exporting variables to shaders
		myShader.setFloat("size", size);
		myShader.setFloat4("color", color[0], color[1], color[2], color[3]);

		// Renders the ImGUI elements
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Deletes all ImGUI instances
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// Delete all the objects we've created
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
	VBO1.Delete();
	VAO1.Delete();
=======
	VAO1.Delete();
	VBO1.Delete();
>>>>>>> Added VBOs, VAOs, EBOs to this branch
	EBO1.Delete();
	myShader.~CustomShader();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window, Camera& currentCam)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		currentCam.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
		std::cout << "GLFW_KEY_W" << std::endl;

	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		currentCam.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
		std::cout << "GLFW_KEY_S" << std::endl;

	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		currentCam.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
		std::cout << "GLFW_KEY_A" << std::endl;

	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		currentCam.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
		std::cout << "GLFW_KEY_D" << std::endl;

	}
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
	WindowWidth = width;
	WindowHeight = height;
}
void UpdateDeltaTime()
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}