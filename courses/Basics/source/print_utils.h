#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#pragma once

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
