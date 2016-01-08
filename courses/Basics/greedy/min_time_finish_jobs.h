#include <vector>

#ifndef BASICS_MIN_TIME_FINISH_JOBS_H
#define BASICS_MIN_TIME_FINISH_JOBS_H

/**
 * Find the minimum completion time given a set of identical assignees
 * and a set of jobs each with a given amount of work units.
 *
 * Constraints:
 * An assignee can only be assigned contiguous jobs.
 * Two assignees cannot share a job.
 */
class MinTimeFinishJobs
{
public:

    MinTimeFinishJobs(
        int num_assignees,
        int assignee_performance,
        const std::vector<int>& job_units
    );


    int findMinCompletionTime();

private:

    int m_num_assignees;
    // time taken by each assignee to finish one unit of job
    int m_assignee_performance;
    // number of units per job
    std::vector<int> m_job_units;

    int job_max_units;
    int total_job_units;
};
#endif //BASICS_MIN_TIME_FINISH_JOBS_H
