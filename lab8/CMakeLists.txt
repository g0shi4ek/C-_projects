cmake_minimum_required(VERSION 3.23)

set(project "lab8")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/111.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/222.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(${project}
        ${${project}_SOURCE_LIST})


