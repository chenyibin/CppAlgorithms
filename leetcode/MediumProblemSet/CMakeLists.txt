cmake_minimum_required(VERSION 3.3)
project(MediumProblemSet)

add_definitions(-std=c++11)

set(SOURCE_FILES problem_set_main.cpp)

add_executable(MediumProblemSet ${SOURCE_FILES})

include_directories(source)

add_subdirectory(source)
add_subdirectory(tests)

target_link_libraries(MediumProblemSet source)
