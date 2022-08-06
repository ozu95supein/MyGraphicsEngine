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
#include "Camera.h"

//callbacks for input and window events
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, Camera &currentCam);


const int & InitialWindowWidth = 800;
const int & InitialWindowHeight = 800;

float deltaTime = 0.0f;  //Gloabal value, time between current frame and last frame
float lastFrame = 0.0f;  //Gloabal value, time of last frame
void UpdateDeltaTime();

glm::vec4 InitialClearColor = { 0.07f, 0.13f, 0.17f, 1.0f };

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
	GLFWwindow* window = glfwCreateWindow(InitialWindowWidth, InitialWindowHeight, "ImGui + GLFW", NULL, NULL);
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
	glViewport(0, 0, InitialWindowWidth, InitialWindowHeight);
	//contruct the camera for the scene
	
	glm::vec3 eye_pos = default_eye_pos;
	glm::vec3 up = default_up;
	glm::vec3 position_to_look_at = default_position_to_look_at;
	float FOV = default_FOV;
	float aspect = (float)InitialWindowWidth / (float)InitialWindowHeight;
	float near = default_near;
	float far = default_far;
	float speed = default_cam_speed;
	//Camera Object
	Camera mainCameraObject(eye_pos, up, position_to_look_at, FOV, aspect, near, far, speed);

	CustomShader myShader("default.vert", "default.frag");
	glEnable(GL_DEPTH_TEST);
	// Vertices coordinates
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};

	// Create reference containers for the Vartex Array Object and the Vertex Buffer Object
	GLuint VAO, VBO;

	// Generate the VAO and VBO with only 1 object each
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(VAO);

	// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(0);

	// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

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
		glBindVertexArray(VAO);
		// Only draw the triangle if the ImGUI checkbox is ticked
		if (drawTriangle)
			// Draw the triangle using the GL_TRIANGLES primitive
			glDrawArrays(GL_TRIANGLES, 0, 3);

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
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
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
}
void UpdateDeltaTime()
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}