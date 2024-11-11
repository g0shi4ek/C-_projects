cmake_minimum_required(VERSION 3.23)

set(project "lab4")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(stack)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST}
        ../lab4/stack/stack.cpp)


target_link_libraries(${project} stack)


