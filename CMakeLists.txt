cmake_minimum_required(VERSION 3.28)

project(psx-renderer)

set(CMAKE_CXX_STANDARD 11) # for some reason glm doesn't support c++ 17

add_executable(${PROJECT_NAME}
    src/main.cpp

)

target_include_directories(${PROJECT_NAME} PRIVATE thirdparty/glad/include) # add glad includes to the target include list