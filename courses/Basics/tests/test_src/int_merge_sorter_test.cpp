#include "gtest/gtest.h"

#include "int_merge_sorter.h"
#include "print_utils.h"

TEST(int_merge_sorter_test, test_six_element_array)
{
    std::vector<int> example = {7,2,5,3,6,1};
    IntMergeSorter sorter(example);
    sorter.sort();
    EXPECT_EQ("[1,2,3,5,6,7]", to_string(example));
}