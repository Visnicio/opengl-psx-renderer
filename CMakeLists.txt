cmake_minimum_required(VERSION 3.28)

project(psx-renderer)

set(CMAKE_CXX_STANDARD 11) # for some reason glm doesn't support c++ 17

add_executable(${PROJECT_NAME}
    src/main.cpp

    #glad
    thirdparty/glad/src/glad.c
)

target_include_directories(${PROJECT_NAME} PRIVATE thirdparty/glad/include) # add glad includes to the target include list
# target_include_directories(${PROJECT_NAME} PRIVATE thirdparty/glfw/include) # just the includes

## GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_X11 ON CACHE BOOL "" FORCE)
add_subdirectory("thirdparty/glfw") # since glfw repo has a cmakelists we can add it as a subdirectory to be compiled and build
target_link_libraries(${PROJECT_NAME} PRIVATE glfw) # then we can add as a library after building, we know that the name of the lib is GLFW cause its the name of the project/target on their cmakelists