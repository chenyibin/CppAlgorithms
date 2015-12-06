#include "skyline_problem.h"

SkylineProblem::SkylineProblem()
: m_height_changes()
{ }

std::vector<std::pair<int, int>> SkylineProblem::getSkyline(std::vector<std::vector<int>>& buildings)
{
    collect_height_changes(buildings);

    std::vector<std::pair<int, int>> skyline;

    std::multiset<int> height_mods;
    int last_height = 0;
    for (auto changes : m_height_changes) {

        for (auto modification : changes.second) {
            if (modification < 0) {
                height_mods.erase(height_mods.find(-modification));
            } else {
                height_mods.insert(modification);
            }
        }

        int x_pos = changes.first;

        int highest = 0;
        if (!height_mods.empty()) {
            highest = *(height_mods.rbegin());
        }
        if (highest != last_height) {
            skyline.emplace_back(x_pos, highest);
            last_height = highest;
        }
    }
    return skyline;
};

void SkylineProblem::collect_height_changes(const std::vector<std::vector<int>>& buildings)
{
    for (auto building : buildings) {
        // assume input has already been verified, no error checking
        int left_x_coord = building[0];
        int right_x_coord = building[1];
        int height = building[2];

        m_height_changes[left_x_coord].insert(height);
        m_height_changes[right_x_coord].insert(-height);
    }
}