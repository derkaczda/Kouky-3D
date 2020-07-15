cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Kouky3d VERSION 0.1)

set(CMAK_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE HEADER_FILES
    src/*.h
)

file(GLOB_RECURSE SOURCE_FILES
    src/*.cpp
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