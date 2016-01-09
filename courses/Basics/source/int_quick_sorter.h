#include <vector>

#pragma once

/**
 * Reviewing Quick Sort
 */
class IntQuickSorter {

    std::vector<int>& m_data;

public:
    IntQuickSorter(std::vector<int>& data);

    void sort();

private:

    void quick_sort(std::size_t left, std::size_t right);

};
