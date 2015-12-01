cmake_minimum_required(VERSION 3.3)

project(source)

add_definitions(-std=c++11)

set(HEADER_FILES int_merge_sorter.h int_min_heap.h print_utils.h)

set(SOURCE_FILES int_merge_sorter.cpp int_min_heap.cpp)

add_library(source STATIC ${SOURCE_FILES} ${HEADER_FILES})