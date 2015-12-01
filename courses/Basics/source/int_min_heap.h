#include <vector>

#ifndef COMBINATORIAL_INT_MIN_HEAP_H
#define COMBINATORIAL_INT_MIN_HEAP_H

class IntMinHeap {
    std::vector<int> m_storage;
public:

    IntMinHeap();
    void insert(int value);
    void delete_min();
    void get_min();

private:
    std::size_t get_parent(const std::size_t& index);
    std::size_t get_left_child(const std::size_t& index);

};
#endif //COMBINATORIAL_INT_MIN_HEAP_H
