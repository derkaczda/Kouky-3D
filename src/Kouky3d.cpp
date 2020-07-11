#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <functional>
#include <vector>

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

        glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete window;
}

void showMultipleWindows(int amount)
{
    int success = glfwInit();
    glfwSetErrorCallback(GLFWErrorCallback);

    std::vector<GLFWwindow*> windows;
    for(int i = 0; i < amount; i++)
    {
        windows.push_back(glfwCreateWindow(800, 600, "window " + i, nullptr, nullptr));
    }
    glfwMakeContextCurrent(windows[0]);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    float count = 0.0f;
    float step = .01f;
    while(true)
    {
        for(int i = 0; i < amount; i++)
        {
            glfwMakeContextCurrent(windows[i]);
            glClearColor(count+(float)i/(float)amount, count+(1.f - (float)i/(float)amount), count+(float)i/(float)amount, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(windows[i]);
            glfwPollEvents();
        }

        count += step;
        if(count > 1.0f)
        {
            count = 1.0f;
            step = -step;
        }
        else if(count < 0.0f)
        {
            count = 0.0f;
            step = -step;
        }
    }
}