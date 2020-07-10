cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Kouky3d VERSION 0.0)

set(CMAK_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(src/Kouky3dConfig.h.in src/Kouky3dConfig.h)

# add the library
add_library(Kouky3d STATIC src/Kouky3dMain.cpp)

target_include_directories(Kouky3d PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
