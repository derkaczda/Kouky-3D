cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(glad VERSION 0.1)

set(CMAK_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PUBLIC_FILES
    include
)

# add the library
add_library(glad STATIC src/glad.c)


target_include_directories(Kouky3d 
    PUBLIC
        ${PUBLIC_FILES}
)
