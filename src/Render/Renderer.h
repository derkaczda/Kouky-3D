#ifndef KOUKY3D_RENDERER
#define KOUKY3D_RENDERER

#include <glm/vec4.hpp>

namespace Kouky3d
{
    class Renderer
    {
    public:

        static void ClearColor(glm::vec4 color);
        static void Clear();
    };
}

#endif