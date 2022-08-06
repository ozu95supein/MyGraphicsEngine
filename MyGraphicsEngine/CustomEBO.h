#pragma once
#include <glad/glad.h>
class CustomEBO
{
public:
	GLuint ID;
	CustomEBO(GLuint* indices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();

private:

};