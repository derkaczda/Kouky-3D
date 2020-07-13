#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <functional>
#include <vector>

#include "../public/Kouky3d.h"

namespace Kouky3d
{
    void setClearColor(float r, float g, float b, float a)
    {
        glClearColor(r,g,b,a);
    }

    void clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}