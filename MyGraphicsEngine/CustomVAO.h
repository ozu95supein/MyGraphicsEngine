#pragma once
#include <glad/glad.h>
#include "CustomVBO.h"

class CustomVAO
{
public:
	//placed outside private for easier access
	GLuint ID;
	CustomVAO();
	
	void LinkVBO(CustomVBO VBO, GLuint layout);
	void Bind();
	void Unbind();
	void Delete();
private:

};