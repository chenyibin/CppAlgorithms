#include <vector>

#pragma once

/**
 * Reviewing Merge Sort
 */
class IntMergeSorter
{
    std::vector<int>& m_data;

public:
    IntMergeSorter(std::vector<int>& data)
    : m_data(data)
    { }

    void sort();

private:

    void merge_sort(std::vector<int>& portion);

    void merge(
        std::vector<int>& portion,
        const std::vector<int>& left,
        const std::vector<int>& right
    );
};
