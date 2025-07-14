cmake_minimum_required(VERSION 3.10)
project(ms1_project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    ms1
    ms1/ms1.cpp
    ms1/Menu.cpp
)
