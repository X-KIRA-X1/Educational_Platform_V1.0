cmake_minimum_required(VERSION 4.0)
project(Educational_Platform)

set(CMAKE_CXX_STANDARD 26)
include_directories(${CMAKE_SOURCE_DIR}/Headers)
include_directories(${CMAKE_SOURCE_DIR}/Database)
include_directories(${CMAKE_SOURCE_DIR}/Source)
add_executable(Educational_Platform Source/main.cpp
        Headers/Student.h
        Headers/Doctor.h
        Headers/System.h
        Source/System.cpp
        Source/Student.cpp
        Headers/AssignmentAnswer.h
        Headers/Course.h
        Source/Doctor.cpp)
