#include "CustomVBO.h"
CustomVBO::CustomVBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
void CustomVBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}
void CustomVBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void CustomVBO::Delete()
{
	glDeleteBuffers(1, &ID);
}