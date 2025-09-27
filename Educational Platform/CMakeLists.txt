cmake_minimum_required(VERSION 3.16)

project(Educational_Platform LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    Source/main.cpp
    Source/System.cpp
    Source/Student.cpp
    Source/Doctor.cpp
)

set(HEADERS
    Headers/Student.h
    Headers/Doctor.h
    Headers/System.h
    Headers/AssignmentAnswer.h
    Headers/Course.h
)

add_executable(Educational_Platform
    ${SOURCES}
    ${HEADERS}        
)

target_include_directories(Educational_Platform
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Headers
        ${CMAKE_SOURCE_DIR}/Database
        ${CMAKE_SOURCE_DIR}/Source
)
