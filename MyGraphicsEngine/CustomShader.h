#ifndef CUSTOM_SHADER_H
#define CUSTOM_SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class CustomShader
{
public:
    // constructor reads and builds the shader
    CustomShader(const char* vertexPath, const char* fragmentPath);
    //destructor
    ~CustomShader();
    GLuint CreateShader(const char* vertexPath, const char* fragmentPath);
    GLuint CompileAttachShader(GLuint programHandle, const char* filename, GLuint shaderType);
    GLuint LinkProgram(GLuint programHandle);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    GLuint GetID();
private:
    // the program ID
    GLuint ID;
};

#endif