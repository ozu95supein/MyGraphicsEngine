#include "CustomVAO.h"

CustomVAO::CustomVAO()
{
	glGenVertexArrays(1, &ID);
}

void CustomVAO::LinkVBO(CustomVBO & VBO, GLuint layout)
{
	VBO.Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void CustomVAO::Bind()
{
	glBindVertexArray(ID);
}
void CustomVAO::Unbind()
{
	glBindVertexArray(0);
}
void CustomVAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}