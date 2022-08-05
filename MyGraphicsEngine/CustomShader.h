#ifndef CUSTOM_SHADER_H
#define CUSTOM_SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <glm/glm.hpp>

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
    void setFloat4(const std::string& name, float value_x, float value_y, float value_z, float value_w) const;
    void setMatrix4(const std::string& name, glm::mat4 * mat) const;
    GLuint GetID();
private:
    // the program ID
    GLuint ID;
};

#endif