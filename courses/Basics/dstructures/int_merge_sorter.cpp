#include <vector>

#include "int_merge_sorter.h"

void IntMergeSorter::sort()
{
    merge_sort(m_data);
}

void IntMergeSorter::merge_sort(std::vector<int>& portion)
{
    std::size_t portion_size = portion.size();
    if (portion_size == 1) {
        return;
    } else if (portion_size == 2) {
        if (portion[0] > portion[1]) {
            std::swap(portion[0], portion[1]);
        }
        return;
    }

    std::size_t left_child_size = portion.size() / 2;
    std::vector<int>::const_iterator mid_iter = portion.begin() + left_child_size;

    std::vector<int> left(portion.cbegin(), mid_iter);
    std::vector<int> right(mid_iter, portion.cend());
    merge_sort(left);
    merge_sort(right);
    merge(portion, left, right);
}

void IntMergeSorter::merge(
    std::vector<int>& portion,
    const std::vector<int>& left,
    const std::vector<int>& right
) {
    std::size_t insert_index = 0;
    std::size_t left_index = 0;
    std::size_t right_index = 0;

    while (left_index < left.size() && right_index < right.size())
    {
        int left_num = left[left_index];
        int right_num = right[right_index];
        if (left_num < right_num) {
            portion[insert_index++] = left_num;
            ++left_index;
        } else {
            portion[insert_index++] = right_num;
            ++right_index;
        }
    }

    while (left_index < left.size()) {
        portion[insert_index++] = left[left_index++];
    }

    while (right_index < right.size()) {
        portion[insert_index++] = right[right_index++];
    }
}
