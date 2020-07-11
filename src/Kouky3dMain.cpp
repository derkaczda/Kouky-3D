#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <functional>

#include "../public/Kouky3d.h"

static void GLFWErrorCallback(int error, const char* description)
{
    std::cout << error << " " << description << std::endl;
}

void showWindow()
{

    int success = glfwInit();
    glfwSetErrorCallback(GLFWErrorCallback);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Kouky 3d", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while(true)
    {
        glfwPollEvents();
    }

    delete window;
}