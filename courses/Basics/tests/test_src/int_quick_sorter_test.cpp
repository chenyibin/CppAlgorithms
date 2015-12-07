#include "gtest/gtest.h"

#include "int_quick_sorter.h"

#include "print_utils.h"

TEST(test_quick_sorter, quick_sort_one_element)
{
    std::vector<int> input = {42};
    IntQuickSorter sorter(input);
    sorter.sort();

    std::vector<int> expected = {42};
    to_string(input);
    ASSERT_EQ(expected, input);
}

TEST(test_quick_sorter, quick_sort_three_elements)
{
    std::vector<int> input = {8,9,100};
    IntQuickSorter sorter(input);
    sorter.sort();

    std::vector<int> expected = {8,9,100};
    to_string(input);
    ASSERT_EQ(expected, input);
}

TEST(test_quick_sorter, quick_sort_four_elements)
{
    std::vector<int> input = {15,7,23,4};
    IntQuickSorter sorter(input);
    sorter.sort();

    std::vector<int> expected = {4,7,15,23};
    to_string(input);
    ASSERT_EQ(expected, input);
}

TEST(test_quick_sorter, quick_sort_five_elements)
{
    std::vector<int> input = {15,7,23,4,100};
    IntQuickSorter sorter(input);
    sorter.sort();

    std::vector<int> expected = {4,7,15,23,100};
    to_string(input);
    ASSERT_EQ(expected, input);
}

TEST(test_quick_sorter, quick_sort_ten_elements)
{
    std::vector<int> input = {1,2,3,4,5,7,5,8,9,100};
    IntQuickSorter sorter(input);
    sorter.sort();

    std::vector<int> expected = {1,2,3,4,5,5,7,8,9,100};
    to_string(input);
    ASSERT_EQ(expected, input);
}
