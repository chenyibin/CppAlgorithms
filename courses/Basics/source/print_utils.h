#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#ifndef COMBINATORIAL_PRINT_UTILS_H
#define COMBINATORIAL_PRINT_UTILS_H

template<class T>
std::string to_string(const std::vector<T>& vec)
{
    std::stringstream out;
    bool first = true;
    out << '[';
    for (auto item : vec) {
        if (first) first = false;
        else out << ',';
        out << item;
    }
    out << ']';
    return out.str();
}
#endif //COMBINATORIAL_PRINT_UTILS_H
