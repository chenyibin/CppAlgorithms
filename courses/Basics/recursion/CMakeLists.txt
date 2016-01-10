cmake_minimum_required(VERSION 3.3)

project(recursion)

add_definitions(-std=c++11)

set(HEADER_FILES alternating_sorted_arrays.h)

set(SOURCE_FILES alternating_sorted_arrays.cpp)

add_library(recursion STATIC ${SOURCE_FILES} ${HEADER_FILES})