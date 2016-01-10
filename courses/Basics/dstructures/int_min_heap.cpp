#include "int_min_heap.h"


IntMinHeap::IntMinHeap()
{
    m_storage.emplace_back(0);
}

void IntMinHeap::insert(int value)
{
    int new_last_index = m_storage.size();
    m_storage.push_back(value);
    swim(new_last_index);
}

void IntMinHeap::delete_min()
{
    if (m_storage.size() == 1) {
        return;
    }
    m_storage[1] = m_storage.back();
    m_storage.pop_back();
    sink(1);
}

int IntMinHeap::get_min() const
{
    // just let m_storage throw exception if empty
    return m_storage[1];
}

bool IntMinHeap::is_empty() const
{
    return (m_storage.size() <= 1);
}


std::size_t IntMinHeap::get_parent(const std::size_t& index)
    const
{
    return index / 2;
}

std::size_t IntMinHeap::get_left_child(const std::size_t& index)
    const
{
    return index * 2;
}

void IntMinHeap::swim(std::size_t index)
{
    while (index > 1) {
        std::size_t parent = get_parent(index);
        if (m_storage[index] < m_storage[parent]) {
            std::swap(m_storage[index], m_storage[parent]);
        } else {
            return;
        }
        index = parent;
    }
}

void IntMinHeap::sink(std::size_t index)
{
    std::size_t left_child = get_left_child(index);
    std::size_t right_child = left_child + 1;
    while (left_child < m_storage.size()) {
        std::size_t min = index;
        if (m_storage[min] > m_storage[left_child])
        {
            min = left_child;
        }
        if (right_child < m_storage.size()
         && m_storage[min] > m_storage[right_child])
        {
            min = right_child;
        }
        if (min == index) {
            return;
        }
        std::swap(m_storage[min], m_storage[index]);
        index = min;
        left_child = get_left_child(index);
        right_child = left_child + 1;
    }
}