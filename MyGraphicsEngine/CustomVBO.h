#pragma once
#include <glad/glad.h>

class CustomVBO
{
public:
	//placed outside private for easier access
	GLuint ID;
	CustomVBO(GLfloat * vertices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();
private:

};