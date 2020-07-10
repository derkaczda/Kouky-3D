
#include "Test/Test.h"
#include <iostream>

#define STRINGIFY(x) #x

void testPrint_impl()
{
}

void testPrint()
{
    std::cout << "before basic function call" << std::endl;
    Kouky3d::basicFunctionCall();
}

void anotherTest()
{
}