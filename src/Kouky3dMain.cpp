
#include <iostream>
#include "../public/Kouky3d.h"

#define STRINGIFY(x) #x

void testPrint_impl()
{
    std::cout << "Version "  << STRINGIFY(KOUKY_3D_VERSION_MAJOR) << "." << STRINGIFY(KOUKY_3D_VERSION_MINOR) << std::endl;
}

void testPrint()
{
    testPrint_impl();
}

void anotherTest()
{
    std::cout << "anotherTest" << std::endl;
}