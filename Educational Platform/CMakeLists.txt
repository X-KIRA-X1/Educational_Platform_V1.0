cmake_minimum_required(VERSION 3.16)
project(Educational_Platform)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
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
