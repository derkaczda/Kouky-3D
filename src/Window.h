#ifndef KOUKY_WINDOW_H
#define KOUKY_WINDOW_H

#include <string>

#include <glm/vec2.hpp>

class GLFWwindow;

namespace Kouky3d
{

    class Window
    {
    public:

        Window(const char* title, const int width, const int height);
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

        inline bool HasContext() { return m_hasContext; }

    private:

        const char* m_title;
        const int m_width;
        const int m_height;

        GLFWwindow* m_windowHandle;
        bool m_hasContext = false;
    };
}

#endif