#include "Window.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

#include "Event/WindowEvents.h"
#include "Event/EventDispatcher.h"

namespace Kouky3d
{
    static void GLFWErrorCallback(int error, const char* description)
    {
        std::cout << error << " " << description << std::endl;
    }

    Window::Window(const char* title, int width, int height)
    {
        m_Data.title = title;
        m_Data.width = width;
        m_Data.height = height;
    }

    Window::~Window()
    {
        Shutdown();
        delete m_windowHandle;
    }

    void Window::Init(bool switchContext)
    {
        glfwSetErrorCallback(GLFWErrorCallback);
        if(glfwInit())
        {
            m_windowHandle = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title, nullptr, nullptr);
            if(switchContext)
            {
                GiveContext();
            }
            glfwSetWindowUserPointer(m_windowHandle, &m_Data);

            glfwSetWindowCloseCallback(m_windowHandle, [](GLFWwindow* window) {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowCloseEvent event;
                data.callback(event);
            });

            glfwSetWindowSizeCallback(m_windowHandle, [](GLFWwindow* window, int width, int height) {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                data.height = height;
                data.width = width;
                WindowResizeEvent event(width, height);
                data.callback(event);
            });

            glfwSetWindowPosCallback(m_windowHandle, [](GLFWwindow* window, int xpos, int ypos) {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowMoveEvent event(xpos, ypos);
                data.callback(event);
            });
        }
    }

    void Window::Shutdown()
    {
        glfwDestroyWindow(m_windowHandle);
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
        glfwPollEvents();
        glfwSwapBuffers(m_windowHandle);
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

    void Window::SetTitle(const std::string& title)
    {
        glfwSetWindowTitle(m_windowHandle, title.c_str());
    }

    void Window::SetSize(glm::vec2 size)
    {
        SetSize(size.x, size.y);
    }

    void Window::SetSize(float width, float height)
    {
        glfwSetWindowSize(m_windowHandle, width, height);
    }

    glm::vec2 Window::GetSize()
    {
        int width, height;
        glfwGetWindowSize(m_windowHandle, &width, &height);
        return { width, height };
    }
}