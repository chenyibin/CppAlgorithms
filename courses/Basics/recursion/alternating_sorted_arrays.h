#include <vector>
#include <string>

#pragma once

class AlternatingSortedArrays
{
    std::vector<int> m_a;
    std::vector<int> m_b;

public:

    AlternatingSortedArrays
    (
        const std::vector<int>& a,
        const std::vector<int>& b
    )
    : m_a(a)
    , m_b(b)
    { }

    std::vector<std::string> generate();

private:

    void generate_a_part(
        std::vector<std::string>& results,
        std::vector<int> result_builder,
        std::size_t a_index,
        std::size_t b_index
    );

    void generate_b_part(
        std::vector<std::string>& results,
        std::vector<int> result_builder,
        std::size_t a_index,
        std::size_t b_index
    );
};
