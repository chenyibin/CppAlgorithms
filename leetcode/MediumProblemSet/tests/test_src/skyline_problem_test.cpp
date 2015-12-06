#include "gtest/gtest.h"

#include "skyline_problem.h"

TEST(skyline_test, test_one_building)
{
    std::vector<std::vector<int>> buildings;
    buildings.emplace_back(std::vector<int>({0,1,3}));
    SkylineProblem solver;
    auto sky_line = solver.getSkyline(buildings);

    std::vector<std::pair<int, int>> expected;
    expected.emplace_back(0,3);
    expected.emplace_back(1,0);

    ASSERT_EQ(expected, sky_line);
}

TEST(skyline_test, test_multi_building)
{
    std::vector<std::vector<int>> buildings =
    {{2,9,10} ,{3,7,15} ,{5,12,12} ,{15,20,10} ,{19,24,8}};

    SkylineProblem solver;
    auto sky_line = solver.getSkyline(buildings);

    std::vector<std::pair<int, int>> expected =
    {{2,10}, {3,15}, {7,12}, {12,0}, {15,10}, {20,8}, {24,0}};

    ASSERT_EQ(expected, sky_line);
}
