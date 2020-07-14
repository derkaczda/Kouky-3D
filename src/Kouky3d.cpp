#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <functional>
#include <string>

#include "Kouky3dConfig.h"
#include "../public/Kouky3d.h"

namespace Kouky3d
{
    std::string Version()
    {
        std::string s;
        s.append(KOUKY_3D_VERSION_MAJOR);
        s.append(".");
        s.append(KOUKY_3D_VERSION_MINOR);
        return s;
    }
}