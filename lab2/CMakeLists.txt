cmake_minimum_required(VERSION 3.23)

set(project "lab2")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(planeta)

add_subdirectory(dom)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dbase.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dbase2.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

target_link_libraries(${project} planeta)
target_link_libraries(${project} dom)




