#include "gtest/gtest.h"
#include "min_time_finish_jobs.h"

TEST(test_min_time_finish_jobs, three_jobs_two_assignees)
{
    std::vector<int> jobs {4, 5, 10};
    MinTimeFinishJobs minTime(2, 5, jobs);
    int minCompletionTime = minTime.findMinCompletionTime();
    ASSERT_EQ(50, minCompletionTime);
}

TEST(test_min_time_finish_jobs, six_jobs_four_assignees)
{
    std::vector<int> jobs {10, 7, 8, 12, 6, 8};
    MinTimeFinishJobs minTime {4, 5, jobs};
    int minCompletionTime = minTime.findMinCompletionTime();
    ASSERT_EQ(75, minCompletionTime);
}
