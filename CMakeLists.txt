cmake_minimum_required(VERSION 3.10)
project(oop244-project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    ms1
    ms1/ms1.cpp
    ms1/Menu.cpp
)

add_executable(
    ms2
    ms2/ms2.cpp
    ms2/Menu.cpp
    ms2/Menu.h
    ms2/Utils.cpp
    ms2/Utils.h
    ms2/constants.h
)
