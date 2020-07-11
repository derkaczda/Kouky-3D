#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <functional>

#include "../public/Kouky3d.h"

static void GLFWErrorCallback(int error, const char* description)
{
    std::cout << error << " " << description << std::endl;
}

void showWindow(const char* title)
{

    int success = glfwInit();
    glfwSetErrorCallback(GLFWErrorCallback);

    GLFWwindow* window = glfwCreateWindow(800, 600, title, nullptr, nullptr);

    glfwMakeContextCurrent(window);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while(true)
    {
        glfwPollEvents();
    }

    delete window;
}