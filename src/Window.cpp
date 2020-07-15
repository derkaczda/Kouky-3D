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
        // TODO: delete window correctly
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
            }
        }
    }

    void Window::Show()
    {
        glfwShowWindow(m_windowHandle);
    }

    void Window::Hide()
    {
        glfwHideWindow(m_windowHandle);
    }

    void Window::GiveContext()
    {
        glfwMakeContextCurrent(m_windowHandle);
    }

    void Window::OnUpdate()
    {
        glfwSwapBuffers(m_windowHandle);
        glfwPollEvents();
    }

    void Window::SetPosition(glm::vec2 position)
    {
        SetPosition(position.x, position.y);
    }

    void Window::SetPosition(float x, float y)
    {
        glfwSetWindowPos(m_windowHandle, x, y);
    }

    glm::vec2 Window::GetPosition()
    {
        int xpos, ypos;
        glfwGetWindowPos(m_windowHandle, &xpos, &ypos);
        return {xpos, ypos};
    }
}