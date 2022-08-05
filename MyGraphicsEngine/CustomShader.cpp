#include "CustomShader.h"

CustomShader::CustomShader(const char* vertexPath, const char* fragmentPath)
{
	ID = CreateShader(vertexPath, fragmentPath);
	
}
CustomShader::~CustomShader()
{
    glDeleteProgram(ID);
}
GLuint CustomShader::CreateShader(const char* vertexPath, const char* fragmentPath)
{
	GLuint handle = glCreateProgram();
	if (handle == 0)
	{
		std::cout << "Unable to create shader program." << std::endl;
        return 0;
	}
    // compile vertex shader
    if (CompileAttachShader(handle, vertexPath, GL_VERTEX_SHADER) == 0)
    {
        std::cout << "Unable to compile and attatch vertex shader program." << std::endl;
        return 0;
    }
    // compile fragment shader
    if (CompileAttachShader(handle, fragmentPath, GL_FRAGMENT_SHADER) == 0)
    {
        std::cout << "Unable to compile and attatch fragment shader program." << std::endl;
        return 0;
    }
    //link program
    if (LinkProgram(handle) == 0)
    {
        std::cout << "Unable to link shader program." << std::endl;
        return 0;
    }
    return handle;
}

GLuint CustomShader::CompileAttachShader(GLuint programHandle, const char* filename, GLuint shaderType)
{
    // load shader file
    std::ifstream inFile(filename, std::ios::in);
    if (!inFile)
    {
        std::cout << "File not found." << std::endl;
        return 0;
    }

    std::ostringstream codeStream;
    while (inFile.good())
    {
        int c = inFile.get();
        if (!inFile.eof())
            codeStream << (char)c;
    }
    inFile.close();

    // Create shader
    GLuint shaderhandle = 0;
    shaderhandle = glCreateShader(shaderType);

    // Set source to shader
    std::string  code = codeStream.str();
    const char* c_code = code.c_str();
    glShaderSource(shaderhandle, 1, &c_code, NULL);

    // Compile the shader
    glCompileShader(shaderhandle);

    // Check for errors
    int result;
    glGetShaderiv(shaderhandle, GL_COMPILE_STATUS, &result);
    if (GL_FALSE == result)
    {
        // Compile failed, store log and return false
        int length = 0;

        glGetShaderiv(shaderhandle, GL_INFO_LOG_LENGTH, &length);
        if (length > 0)
        {
            char* c_log = new char[static_cast<size_t>(length) + 1];
            int    written = 0;
            glGetShaderInfoLog(shaderhandle, length, &written, c_log);
            std::cout << c_log << std::endl;
            delete[] c_log;
        }
        return 0;
    }
    else
    {
        // Compile succeeded, attach shader and return true
        glAttachShader(programHandle, shaderhandle);

        glDeleteShader(shaderhandle);
        return programHandle;
    }
}

GLuint CustomShader::LinkProgram(GLuint programHandle)
{
    if (programHandle <= 0)
        return 0;

    // Link shader program
    glLinkProgram(programHandle);

    // Check for errors
    int status = 0;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &status);
    if (GL_FALSE == status)
    {
        // Store log and return false
        int length = 0;

        glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &length);
        if (length > 0)
        {
            char* c_log = new char[static_cast<size_t>(length) + 1];
            int    written = 0;
            glGetProgramInfoLog(programHandle, length, &written, c_log);
            std::cout << c_log << std::endl;
            delete[] c_log;
        }

        return 0;
    }
    return programHandle;
}
void CustomShader::use()
{
    glUseProgram(ID);
}

void CustomShader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void CustomShader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void CustomShader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void CustomShader::setFloat4(const std::string& name, float value_x, float value_y, float value_z, float value_w) const
{
    glUniform4f(glGetUniformLocation(ID, name.c_str()), value_x, value_y, value_z, value_w);
}
void CustomShader::setMatrix4(const std::string& name, glm::mat4 * mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, (const GLfloat *)mat);
}
GLuint CustomShader::GetID()
{
    return ID;
}