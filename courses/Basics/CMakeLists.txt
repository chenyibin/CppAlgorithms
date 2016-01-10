cmake_minimum_required(VERSION 3.3)
project(Basics)

add_definitions(-std=c++11)

set(SOURCE_FILES basics_main.cpp)

add_executable(Basics ${SOURCE_FILES})

include_directories(dstructures)
include_directories(greedy)
include_directories(recursion)

add_subdirectory(dstructures)
add_subdirectory(greedy)
add_subdirectory(recursion)
add_subdirectory(tests)

target_link_libraries(Basics dstructures greedy recursion)