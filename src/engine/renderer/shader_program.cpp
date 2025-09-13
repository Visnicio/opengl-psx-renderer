#include "shader_program.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "utils/utils.h"

ShaderProgram::ShaderProgram(const std::string &vertexShaderFile, const std::string &fragShaderFile)
{
    std::string vertexShaderString = Utils::GetFileContents(vertexShaderFile);
    std::string fragmentShaderString = Utils::GetFileContents(fragShaderFile);
    const char* vertexSource = vertexShaderString.c_str();
    const char* fragmentSource = fragmentShaderString.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // --- Compilation
    int  success;
    char infoLog[512];

    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAG::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // --- 


    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID); //link both shaders
    
    // Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void ShaderProgram::Use()
{
    glUseProgram(ID);
}

void ShaderProgram::Delete()
{
    glDeleteProgram(ID);
}
