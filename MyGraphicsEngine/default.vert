#version 330 core
//default shader code

//Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Outputs the color for the Fragment Shader
out vec3 color;
uniform float size;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
	// Outputs the positions/coordinates of all vertices
	gl_Position = vec4(aPos.x + aPos.x * size, aPos.y + aPos.y * size, aPos.z + aPos.z * size, 1.0);
	// Assigns the colors from the Vertex Data to "color"
	color = aColor;
}