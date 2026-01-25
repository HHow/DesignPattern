cmake_minimum_required(VERSION 3.10)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
message("c++ stl 17")

project(Practice_C++ VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_VERBOSE_MAKEFILE true)

add_subdirectory(Factory)
add_subdirectory(Component)

# main 실행 파일을 만드는 부분
add_executable(main main.cpp)

target_link_libraries(main Factory Component)

#----------- 이전 cmake

#message("main CMakeLists.txt")

#add_subdirectory(Factory)
#add_subdirectory(Component)

#set(LIBRARIES Factory Component)

#foreach(LIBRARY ${LIBRARIES})
#  set(LIB_OBJS ${LIB_OBJS} $<TARGET_OBJECTS:${LIBRARY}>)
#endforeach()

#add_library(${PROJECT_NAME} STATIC ${LIB_OBJS})

#add_executable(main main.cpp)