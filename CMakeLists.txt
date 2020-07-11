cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Kouky3d VERSION 0.1)

set(CMAK_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADER_FILES
    src/Test/Test.h
)

set(SOURCE_FILES
    src/Kouky3dMain.cpp
    src/Test/Test.cpp
)

set(PUBLIC_FILES
    public
)

# add the library
add_library(Kouky3d STATIC ${SOURCE_FILES})

target_link_libraries(Kouky3d
    PRIVATE
        glfw
        glm
        glad
)


target_include_directories(Kouky3d 
    PUBLIC
        ${PUBLIC_FILES}
    PRIVATE
        ${HEADER_FILES}
)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/glad)