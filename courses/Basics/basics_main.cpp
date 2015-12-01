#include <iostream>

#include "print_utils.h"
#include "int_merge_sorter.h"

int main() {

    std::vector<int> example = {1,2,5,2,3,6,7,4,5,6};
    IntMergeSorter sorter(example);
    sorter.sort();
    std::cout << to_string(example) << std::endl;
    return 0;
}