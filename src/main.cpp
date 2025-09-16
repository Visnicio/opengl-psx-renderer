#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/engine.h"
#include "engine/renderer/shader_program.h"
#include "engine/renderer/vbo.h"

#include "utils/utils.h"

int main() {

    Engine engine;
    engine.Init();

    ShaderProgram shaderProgram("src/shaders/vert.glsl", "src/shaders/frag.glsl");

    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };
    
    VBO triangleVBO(vertices);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    // ..:: Initialization code (done once (unless your object frequently changes)) :: ..
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, triangleVBO.GetId());
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 

    while(!glfwWindowShouldClose(engine.GetWindow()))
    {
        glfwSwapBuffers(engine.GetWindow());
        glfwPollEvents();

        glClearColor(0.24f, 0.3f, 0.3f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        shaderProgram.Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    std::cout << "Hello World \n";

    engine.Cleanup();

    return 0;
}