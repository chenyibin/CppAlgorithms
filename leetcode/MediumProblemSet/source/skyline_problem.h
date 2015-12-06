#include <vector>
#include <tuple>
#include <set>
#include <map>

#ifndef MEDIUMPROBLEMSET_SKYLINE_PROBLEM_H
#define MEDIUMPROBLEMSET_SKYLINE_PROBLEM_H

class SkylineProblem
{
    std::map<int,std::set<int>> m_height_changes;

public:

    SkylineProblem();

    /**
     * List of buildings are given in the format [Li, Ri, Hi]
     * Li - x coordinate of left edge
     * Ri - x coordinate of right edge
     * Hi - height of building
     */
    std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings);

private:
    void collect_height_changes(const std::vector<std::vector<int>>& buildings);
};
#endif //MEDIUMPROBLEMSET_SKYLINE_PROBLEM_H
