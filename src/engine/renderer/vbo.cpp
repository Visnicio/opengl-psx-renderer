#include "vbo.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

VBO::VBO(const float vertices[])
{
    glGenBuffers(1, &this->ID);
    
    glBindBuffer(GL_ARRAY_BUFFER, this->ID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(&vertices), vertices, GL_STATIC_DRAW);
}