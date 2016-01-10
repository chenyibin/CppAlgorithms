include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES
    alternating_sorted_arrays_test.cpp
    int_merge_sorter_test.cpp
    int_quick_sorter_test.cpp
    min_time_finish_jobs_test.cpp
    int_min_heap_test.cpp)

add_executable(runtests ${SOURCE_FILES})

target_link_libraries(runtests gtest gtest_main)
target_link_libraries(runtests dstructures greedy recursion)
