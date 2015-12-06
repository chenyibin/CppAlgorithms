include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES bin_tree_longest_sequence_test.cpp bin_tree_paths_test.cpp longest_substring_no_repeated_char_test.cpp skyline_problem_test.cpp super_ugly_number_test.cpp)

add_executable(runtests ${SOURCE_FILES})

target_link_libraries(runtests gtest gtest_main)
target_link_libraries(runtests source)
