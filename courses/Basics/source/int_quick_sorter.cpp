#include <iostream>

#include "int_quick_sorter.h"

IntQuickSorter::IntQuickSorter(std::vector<int>& data)
:m_data(data)
{ }

void IntQuickSorter::sort()
{
    quick_sort(0, m_data.size());
}

void IntQuickSorter::quick_sort(std::size_t left, std::size_t right)
{
    std::size_t diff = right - left;
    if (diff == 1) {
        return;
    }

    if (diff == 2) {
        size_t right_index = left + 1;
        if (m_data[left] > m_data[right_index]) {
            std::swap(m_data[left], m_data[right_index]);
        }
        return;
    }

    // move_pivot_to_left(left, right);

    int& pivot = m_data[left];
    // everything to the left of pivot_point is less than pivot
    // (not including the pivot itself)
    std::size_t pivot_point = left + 1;
    for (std::size_t i = pivot_point; i < right; ++i) {
        if (m_data[i] < pivot) {
            std::swap(m_data[i], m_data[pivot_point]);
            ++pivot_point;
        }
    }

    std::size_t pivot_location = pivot_point - 1;
    std::swap(pivot, m_data[pivot_location]);
    if (pivot_location > left) {
        quick_sort(left, pivot_location);
    }

    // conveniently pivot_point is just one greater than pivot_location
    if (pivot_point < right) {
        quick_sort(pivot_point, right);
    }
}
