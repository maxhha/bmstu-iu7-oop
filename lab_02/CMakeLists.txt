cmake_minimum_required(VERSION 3.0)
project(lab2 LANGUAGES CXX)

add_executable(${PROJECT_NAME} ./unit_tests/unit_main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE inc)
