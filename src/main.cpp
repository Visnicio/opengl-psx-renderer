#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/engine.h"

int main() {

    Engine engine;
    engine.Init();

    while(!glfwWindowShouldClose(engine.GetWindow()))
    {
        glfwSwapBuffers(engine.GetWindow());
        glfwPollEvents();

        glClearColor(0.24f, 0.3f, 0.3f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    std::cout << "Hello World \n";

    engine.Cleanup();

    return 0;
}