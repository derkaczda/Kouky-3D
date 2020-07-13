#ifndef KOUKY_WINDOW_H
#define KOUKY_WINDOW_H

#include <string>

class GLFWwindow;

namespace Kouky3d
{

    class Window
    {
    public:

        Window(const char* title, const int width, const int height);
        ~Window();

        void Init(const bool switchContext=true);

        void Show();
        void Hide();

        void OnUpdate();

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