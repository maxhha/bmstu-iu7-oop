cmake_minimum_required(VERSION 3.0)
project(lab2 LANGUAGES CXX)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "unit_tests/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE inc)
