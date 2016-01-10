#include "gtest/gtest.h"

#include "alternating_sorted_arrays.h"

TEST(test_alt_sort_arrays, simple_example_case)
{
    std::vector<int> a {10, 15, 25};
    std::vector<int> b {1, 5, 20, 30};
    AlternatingSortedArrays sorter(a, b);
    auto result = sorter.generate();
    ASSERT_EQ(7, result.size());
    std::vector<std::string> expected = {
        "[10,20]", "[10,20,25,30]", "[10,30]",
        "[15,20]", "[15,20,25,30]", "[15,30]",
        "[25,30]",
    };
    ASSERT_EQ(expected, result);
}