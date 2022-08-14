<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include "Texture.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Camera.h"

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
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

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
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
=======
#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
=======
>>>>>>> 3d added. Tut 7

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369


>>>>>>> I quit, Im restarting this ffing project from scratch
=======
=======
#include "Mesh.h"
>>>>>>> Mesh class implemented alongside lighting and texture shader stuff
const unsigned int width = 800;
const unsigned int height = 800;

>>>>>>> .
// Vertices coordinates
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
/*****************************************************************************/
=======

=======
>>>>>>> .
// Vertices coordinates
>>>>>>> Added VBOs, VAOs, EBOs to this branch
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
	-1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
	-1.0f, 0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 1.0f, 0.0f,
	 1.0f, 0.0f, -1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
	 1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f, 0.0f
=======
Vertex vertices[] =
{ //               COORDINATES           /            COLORS          /           TexCoord         /       NORMALS         //
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
>>>>>>> Mesh class implemented alongside lighting and texture shader stuff
};
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
=======

>>>>>>> Added VBOs, VAOs, EBOs to this branch
// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3
};

Vertex lightVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
/*****************************************************************************/
=======
>>>>>>> Added VBOs, VAOs, EBOs to this branch

=======
=======
#include"Model.h"

const unsigned int width = 800;
const unsigned int height = 800;

>>>>>>> Made a model Loader using gtlf
/****************************************************************************/
double Global_Delta_Time = 0.1;
double Global_Time_LastFrame = 0.0;
double Global_CurrentTime = 0.0;
unsigned int Global_FrameCounter = 0;
double Global_FrameTimeStep = 1.0 / 30.0;
void UpdateTimestep(GLFWwindow* window);
/****************************************************************************/
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
>>>>>>> Basic Lighting done, we will move on to specular maps
=======

>>>>>>> Mesh class implemented alongside lighting and texture shader stuff
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
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
	GLFWwindow* window = glfwCreateWindow(WindowWidth, WindowHeight, "Oscar's Game Engine", NULL, NULL);
=======
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
>>>>>>> I quit, Im restarting this ffing project from scratch
=======
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
>>>>>>> Mesh class implemented alongside lighting and texture shader stuff
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
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
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
	
=======
	glViewport(0, 0, 800, 800);




=======
	glViewport(0, 0, width, height);
>>>>>>> Mesh class implemented alongside lighting and texture shader stuff


	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369


>>>>>>> I quit, Im restarting this ffing project from scratch
=======
>>>>>>> .
=======
>>>>>>> Specular maps complete
	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
>>>>>>> Added VBOs, VAOs, EBOs to this branch

=======
>>>>>>> Specular maps complete
	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
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
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	
	glm::mat4 view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = mainCameraObject.GetViewMatrix();
	glm::mat4 projection;
	projection = mainCameraObject.GetProjectionMatrix();
=======
	//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -20.0f));
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), (float)InitialWindowWidth / (float)InitialWindowHeight, 0.01f, 100.0f);
>>>>>>> transformations are wrong

	myShader.setMatrix4("model", &model);
	myShader.setMatrix4("view", &view);
	myShader.setMatrix4("projection", &projection);
	///////////////////////////////////////////////////////////////////////////

	// Specify the color of the background
	glClearColor(InitialClearColor.x, InitialClearColor.y, InitialClearColor.z, InitialClearColor.w);
=======
	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
>>>>>>> I quit, Im restarting this ffing project from scratch


<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
		//Process Input from the user 
		processInput(window, mainCameraObject);

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
		//Update camera Matrices in the shader
		view = mainCameraObject.GetViewMatrix();
		projection = mainCameraObject.GetProjectionMatrix();
		myShader.setMatrix4("view", &view);
		myShader.setMatrix4("projection", &projection);
=======
>>>>>>> I quit, Im restarting this ffing project from scratch

	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 6 - Textures/";

	// Texture
	Texture popCat((parentDir + texPath + "pop_cat.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
=======
	Texture popCat("pop_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
>>>>>>> Copied and pasted everything from video 6, TEXTURES
=======
=======
>>>>>>> .
	Texture popCat("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
>>>>>>> 3d added. Tut 7
	popCat.texUnit(shaderProgram, "tex0", 0);
=======
	//LIGHT CUBE OBJECT AND LIGHT SHADER CODE
	/****************************************************************************/
=======
	// Store mesh data in vectors for the mesh
	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	// Create floor mesh
	Mesh floor(verts, ind, tex);


>>>>>>> Mesh class implemented alongside lighting and texture shader stuff
	// Shader for light cube
	Shader lightShader("light.vert", "light.frag");
	// Store mesh data in vectors for the mesh
	std::vector <Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector <GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	// Crate light mesh
	Mesh light(lightVerts, lightInd, tex);




=======
>>>>>>> Made a model Loader using gtlf
=======
	// Shader for the outlining model
	Shader outliningProgram("outlining.vert", "outlining.frag");
>>>>>>> Something is Wrong with the Stencil Buffer, need to check stuff 1 by 1

	// Take care of all the light related things
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369


	Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);
>>>>>>> Basic Lighting done, we will move on to specular maps
=======
	Texture planksTex("planks.png", GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE);
	planksTex.texUnit(shaderProgram, "tex0", 0);
	Texture planksSpec("planksSpec.png", GL_TEXTURE_2D, 1, GL_RED, GL_UNSIGNED_BYTE);
	planksSpec.texUnit(shaderProgram, "tex1", 1);
>>>>>>> Specular maps complete
=======
>>>>>>> Mesh class implemented alongside lighting and texture shader stuff

=======
>>>>>>> Added all models to see what happens
	// Enables the Depth Buffer	
	glEnable(GL_DEPTH_TEST);
	// Enables Face Culling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CCW);

	// Enables the Stencil Buffer	
	glEnable(GL_STENCIL_TEST);
	// Sets rules for outcomes of stecil tests	
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	// Creates camera object	
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));


	// Original code from earlier tutorials
	//Model ground("models/ground/scene.gltf");
	//Model trees("models/trees/scene.gltf");
	//
	//// Load in models
	//Model model("models/crow/scene.gltf");
	//Model outline("models/crow-outline/scene.gltf");
	Model statue("models/statue/scene.gltf");



	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		//update the timestep to maintain the framerate
		UpdateTimestep(window);
		// Specify the color of the background		
		glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		// Handles camera inputs		
		camera.Inputs(window, (float)Global_Delta_Time);
		// Updates and exports the camera matrix to the Vertex Shader		
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		// Make it so the stencil test always passes
		glStencilFunc(GL_ALWAYS, 1, 0xFF);
		// Enable modifying of the stencil buffer
		glStencilMask(0xFF);

		// Draw models	
		//ground.Draw(shaderProgram, camera);
		//trees.Draw(shaderProgram, camera);
		//model.Draw(shaderProgram, camera);
		 
		statue.Draw(shaderProgram, camera);

		//***************************IMPORTANT*************************************//
		// Make it so only the pixels without the value 1 pass the test		
		glStencilFunc(GL_NOTEQUAL, 1, 0xFF);				//Without this the stencil buffer overrides the color buffer ant its all white
		// Disable modifying of the stencil buffer		
		glStencilMask(0x00);
		// Disable the depth buffer		
		glDisable(GL_DEPTH_TEST);
		//***************************IMPORTANT*************************************//
		// Third method from the tutorial	
		//outline.Draw(outliningProgram, camera);

		// Enable modifying of the stencil buffer	
		glStencilMask(0xFF);
		// Clear stencil buffer	
		glStencilFunc(GL_ALWAYS, 0, 0xFF);
		// Enable the depth buffer	
		glEnable(GL_DEPTH_TEST);


		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
	VBO1.Delete();
	VAO1.Delete();
=======
	VAO1.Delete();
	VBO1.Delete();
>>>>>>> Added VBOs, VAOs, EBOs to this branch
	EBO1.Delete();
	planksTex.Delete();
	planksSpec.Delete();
=======
>>>>>>> Mesh class implemented alongside lighting and texture shader stuff
	shaderProgram.Delete();
	outliningProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
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
=======
>>>>>>> I quit, Im restarting this ffing project from scratch
=======
}

void UpdateTimestep(GLFWwindow* window)
{
	Global_CurrentTime = glfwGetTime();
	Global_Delta_Time = Global_CurrentTime - Global_Time_LastFrame;
	Global_Time_LastFrame = Global_CurrentTime;
<<<<<<< d1b6c5a5e16696bdb6ae98568c0c79773e79b369
>>>>>>> Basic Lighting done, we will move on to specular maps
=======
	Global_FrameCounter++;
	if (Global_Delta_Time >= Global_FrameTimeStep)
	{
		//create new title with frames
		// Creates new title
		std::string FPS = std::to_string((1.0 / Global_Delta_Time) * Global_FrameCounter);
		std::string ms = std::to_string((Global_Delta_Time / Global_FrameCounter) * 1000);
		std::string newTitle = "YoutubeOpenGL - " + FPS + "FPS / " + ms + "ms";
		glfwSetWindowTitle(window, newTitle.c_str());

		// Resets times and counter
		Global_Time_LastFrame = Global_CurrentTime;
		Global_FrameCounter = 0;
	}
>>>>>>> enabled culling and made a frame counter
}