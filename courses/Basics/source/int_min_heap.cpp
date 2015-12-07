#include "int_min_heap.h"


IntMinHeap::IntMinHeap()
{
    m_storage.emplace_back(0);
}

void IntMinHeap::insert(int value)
{

}

std::size_t IntMinHeap::get_parent(const std::size_t& index)
{
    return index / 2;
}

std::size_t IntMinHeap::get_left_child(const std::size_t& index)
{
    return index * 2;
}

