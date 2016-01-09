#include <vector>

#pragma once

/**
 * Reviewing Heaps.
 * (Without using std::priority_queue or std::make_heap)
 */
class IntMinHeap
{
    std::vector<int> m_storage;
public:

    IntMinHeap();
    void insert(int value);
    void delete_min();
    int  get_min() const;

private:

    std::size_t get_parent(const std::size_t& index) const;
    std::size_t get_left_child(const std::size_t& index) const;

    void swim(std::size_t index);
    void sink(std::size_t index);
};
