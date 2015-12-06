#include "gtest/gtest.h"

#include "super_ugly_number.h"

TEST(ugly_number_test, test_second_ugly_number)
{
    std::vector<int> primes = {2,3,5};
    SuperUglyNumber solver;
    int ugly_num = solver.nthSuperUglyNumber(2, primes);

    ASSERT_EQ(2, ugly_num);
}


TEST(ugly_number_test, test_third_ugly_number)
{
    std::vector<int> primes = {2,3,5};
    SuperUglyNumber solver;
    int ugly_num = solver.nthSuperUglyNumber(3, primes);

    ASSERT_EQ(3, ugly_num);

}

TEST(ugly_number_test, test_twelveth_ugly_number)
{
    std::vector<int> primes = {2,7,13,19};
    SuperUglyNumber solver;
    int ugly_num = solver.nthSuperUglyNumber(12, primes);

    ASSERT_EQ(32, ugly_num);

}