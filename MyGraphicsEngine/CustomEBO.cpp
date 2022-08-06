#include "CustomEBO.h"
CustomEBO::CustomEBO(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}
void CustomEBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}
void CustomEBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void CustomEBO::Delete()
{
	glDeleteBuffers(1, &ID);
}