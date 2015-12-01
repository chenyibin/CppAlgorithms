cmake_minimum_required(VERSION 3.3)
project(Basics)

add_definitions(-std=c++11)

set(SOURCE_FILES basics_main.cpp)

add_executable(Basics ${SOURCE_FILES})

include_directories(source)

add_subdirectory(source)
add_subdirectory(tests)

target_link_libraries(Basics source)