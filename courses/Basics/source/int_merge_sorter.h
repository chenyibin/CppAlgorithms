#include <vector>

#ifndef COMBINATORIAL_INT_MERGE_SORTER_H
#define COMBINATORIAL_INT_MERGE_SORTER_H

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
#endif //COMBINATORIAL_INT_MERGE_SORTER_H
