cmake_minimum_required(VERSION 3.10)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message("CMAKE in Component c++ 14")

set (SOURCES
     ./src/Activity.cpp
     ./src/Facade.cpp
     ./src/Map.cpp
     ./src/Unit.cpp
     ./src/User.cpp)

add_library(Component STATIC ${SOURCES})

#----------------------

#project(Component)
#file(GLOB SOURCES src/*.cpp)
#add_library(${PROJECT_NAME} OBJECT ${SOURCES})
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
