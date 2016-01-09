#include "gtest/gtest.h"

#include "int_min_heap.h"

TEST(test_min_heap, empty_to_filled_to_empty)
{
    IntMinHeap heap;

    heap.insert(4);
    heap.insert(3);
    heap.insert(6);
    heap.insert(1);

    ASSERT_EQ(1, heap.get_min());
    heap.delete_min();
    ASSERT_EQ(3, heap.get_min());
    heap.delete_min();
    ASSERT_EQ(4, heap.get_min());
    heap.delete_min();
    ASSERT_EQ(6, heap.get_min());
}

