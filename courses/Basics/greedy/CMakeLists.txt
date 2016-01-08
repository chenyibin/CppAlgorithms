cmake_minimum_required(VERSION 3.3)

project(greedy)

add_definitions(-std=c++11)

set(HEADER_FILES min_time_finish_jobs.h)

set(SOURCE_FILES min_time_finish_jobs.cpp)

add_library(greedy STATIC ${SOURCE_FILES} ${HEADER_FILES})