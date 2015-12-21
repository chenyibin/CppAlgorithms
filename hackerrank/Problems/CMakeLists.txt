cmake_minimum_required(VERSION 3.3)
project(Problems)

add_definitions(-std=c++11)

set(SOURCE_FILES problem_set_main.cpp)

add_executable(Solution ${SOURCE_FILES})

include_directories(source)

add_subdirectory(source)
add_subdirectory(tests)

target_link_libraries(Solution source)
