cmake_minimum_required(VERSION 3.3)

project(source)

add_definitions(-std=c++11)

set(HEADER_FILES bin_tree_longest_sequence.h bin_tree_paths.h longest_substring_no_repeated_char.h serialize_bin_tree.h)
list(APPEND HEADER_FILES tree_node.h)

set(SOURCE_FILES bin_tree_longest_sequence.cpp bin_tree_paths.cpp longest_substring_no_repeated_char.cpp serialize_bin_tree.cpp)

add_library(source STATIC ${SOURCE_FILES} ${HEADER_FILES})
