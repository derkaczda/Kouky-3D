
#include <iostream>
#include "src/Kouky3dConfig.h"

#define STRINGIFY(x) #x

void testPrint()
{
    std::cout << "Version "  << STRINGIFY(KOUKY_3D_VERSION_MAJOR) << "." << STRINGIFY(KOUKY_3D_VERSION_MINOR) << std::endl;
}