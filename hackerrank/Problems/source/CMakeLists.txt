cmake_minimum_required(VERSION 3.3)

project(source)

add_definitions(-std=c++11)

set(HEADER_FILES linked_lists.h)

set(SOURCE_FILES reverse_linked_list.cpp node.h )

add_library(source STATIC ${SOURCE_FILES} ${HEADER_FILES})
