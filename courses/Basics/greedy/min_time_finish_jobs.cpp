//
// Created by Yibin on 1/7/2016.
//
#include "min_time_finish_jobs.h"

MinTimeFinishJobs::MinTimeFinishJobs
(
    int num_assignees,
    int assignee_performance,
    const std::vector<int>& job_units
)
: m_num_assignees(num_assignees)
, m_assignee_performance(assignee_performance)
, m_job_units(job_units)
, m_job_max_units(0)
, m_total_job_units(0)
{
    // Set the total number of jobs units
    // and the maximum number of job units per job
    for (auto job : m_job_units) {
        m_total_job_units += job;
        m_job_max_units = std::max(m_job_max_units, job);
    }
}

int MinTimeFinishJobs::findMinCompletionTime()
{
    // perform a binary search on the minimum completion time

    int start = 0;
    int end = m_total_job_units;
    int minCompletionTime = m_total_job_units;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid >= m_job_max_units && completable(mid)) {
            minCompletionTime = std::min(minCompletionTime, mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return minCompletionTime * m_assignee_performance;
}

bool MinTimeFinishJobs::completable(int time)
{
    int job_index = 0;
    for (int i = 0; i < m_num_assignees; ++i) {
        int work_with_this_job = m_job_units[job_index];
        while (work_with_this_job <= time) {
            if (++job_index >= m_job_units.size()) {
                return true;
            }
            work_with_this_job += m_job_units[job_index];
        }
    }
    return false;
}

