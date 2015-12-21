include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES empty.cpp)

add_executable(runtests ${SOURCE_FILES})

target_link_libraries(runtests gtest gtest_main)
target_link_libraries(runtests source)
