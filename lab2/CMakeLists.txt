cmake_minimum_required(VERSION 3.5)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Set.hpp
        test.cpp
        )
add_executable(lab2 ${SOURCE_FILES})