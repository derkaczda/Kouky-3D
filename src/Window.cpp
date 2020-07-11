#include "Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

namespace Kouky3d
{
    static void GLFWErrorCallback(int error, const char* description)
    {
        std::cout << error << " " << description << std::endl;
    }

    Window::Window(const char* title, const int width, const int height)
        : m_title(title), m_width(width), m_height(height)
    {

    }

    Window::~Window()
    {

    }

    void Window::Init(bool switchContext)
    {
        glfwSetErrorCallback(GLFWErrorCallback);
        if(glfwInit())
        {
            m_windowHandle = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
            if(switchContext)
            {
                GiveContext();
                gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
            }
        }
    }

    void Window::Show()
    {
        glfwShowWindow(m_windowHandle);
        while(true)
        {
            glfwPollEvents();
        }
    }

    void Window::Hide()
    {
        glfwHideWindow(m_windowHandle);
    }

    void Window::GiveContext()
    {
        glfwMakeContextCurrent(m_windowHandle);
    }
}