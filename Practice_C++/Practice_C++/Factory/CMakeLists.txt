
set (SOURCES
     ./src/Factory.cpp)

add_library(Factory STATIC ${SOURCES})
#-------------------------

#project(Factory)
#file(GLOB SOURCES src/*.cpp)
#add_library(${PROJECT_NAME} OBJECT ${SOURCES})
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
