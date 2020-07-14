#include "Renderer.h"
#include <glad/glad.h>

namespace Kouky3d
{
    void Renderer::ClearColor(glm::vec4 color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Renderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}