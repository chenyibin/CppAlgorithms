#include <vector>

#ifndef BASICS_INT_QUICK_SORTER_H
#define BASICS_INT_QUICK_SORTER_H


class IntQuickSorter {

    std::vector<int>& m_data;

public:
    IntQuickSorter(std::vector<int>& data);

    void sort();

private:

    void quick_sort(std::size_t left, std::size_t right);

};


#endif //BASICS_INT_QUICK_SORTER_H
