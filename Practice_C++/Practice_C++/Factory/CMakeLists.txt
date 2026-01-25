cmake_minimum_required(VERSION 3.10)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message("CMAKE in Factory c++ 17")

set (SOURCES
     ./src/Factory.cpp)

add_library(Factory STATIC ${SOURCES})
#-------------------------

#project(Factory)
#file(GLOB SOURCES src/*.cpp)
#add_library(${PROJECT_NAME} OBJECT ${SOURCES})
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
