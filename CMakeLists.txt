cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Kouky3d VERSION 0.1)

set(CMAK_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the library
add_library(Kouky3d STATIC src/Kouky3dMain.cpp)

set(INCLUDE_DIR
    public
)

set(PRIVATE_DIR
    src/Kouky3dConfig.h,
    src/Kouky3d_private.h
)

target_include_directories(Kouky3d 
    PUBLIC
        ${INCLUDE_DIR}
    PRIVATE
        ${PRIVATE_DIR}
)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)