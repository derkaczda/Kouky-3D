#ifndef KOUKY_WINDOW_H
#define KOUKY_WINDOW_H

#include <string>
#include <functional>
#include <glm/vec2.hpp>

#include "Event/Event.h"

class GLFWwindow;

namespace Kouky3d
{

    class Window
    {
    public:

        using WindowEventCallbackFunction = std::function<void(Event&)>;

        Window(const char* title, int width, int height);
        ~Window();

        void Init(const bool switchContext=true);
        void Shutdown();

        void Show();
        void Hide();

        void OnUpdate();

        void SetPosition(glm::vec2 position);
        void SetPosition(float x, float y);
        glm::vec2 GetPosition();


        void SetTitle(const std::string& title);

        void SetSize(glm::vec2 size);
        void SetSize(float widht, float height);
        glm::vec2 GetSize();

        void GiveContext();

        inline GLFWwindow* GetHandle() { return m_windowHandle; }

        inline bool HasContext() { return m_hasContext; }
        inline void SetCallback(const WindowEventCallbackFunction& callback) { m_Data.callback = callback; }

    private:

        GLFWwindow* m_windowHandle;
        bool m_hasContext = false;

        struct WindowData
        {
            const char* title;
            int width;
            int height;
            WindowEventCallbackFunction callback;
        };

        WindowData m_Data;
    };
}

#endif