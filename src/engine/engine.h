#ifndef ENGINE_H
#define ENGINE_H

class GLFWwindow; // forward declaration

class Engine
{
private:
    GLFWwindow* window;

public:

    int Init();
    // void Draw();
    // void Input();
    // void Process();
    void Cleanup();

    GLFWwindow* GetWindow() { return this->window; }
};

#endif


