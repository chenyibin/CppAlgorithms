#include "gtest/gtest.h"

#include "longest_substring_no_repeated_char.h"

TEST(no_repeated_char_test, test_one_char)
{
    LongestSubstringNoRepeatedChar solver;
    int length = solver.lengthOfLongestSubstring("y");
    ASSERT_EQ(1,length);
}

TEST(no_repeated_char_test, test_two_repeated_chars)
{
    LongestSubstringNoRepeatedChar solver;
    int length = solver.lengthOfLongestSubstring("aa");
    ASSERT_EQ(1,length);
}

TEST(no_repeated_char_test, test_three_repeated_chars)
{
    LongestSubstringNoRepeatedChar solver;
    int length = solver.lengthOfLongestSubstring(",,,");
    ASSERT_EQ(1,length);
}

TEST(no_repeated_char_test, test_repeated_chars_first_and_last)
{
    LongestSubstringNoRepeatedChar solver;
    int length = solver.lengthOfLongestSubstring("ammzuxa");
    ASSERT_EQ(5,length);
}
