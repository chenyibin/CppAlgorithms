#include "alternating_sorted_arrays.h"

#include "print_utils.h"

std::vector<std::string> AlternatingSortedArrays::generate()
{
    std::vector<std::string> result;
    std::vector<int> result_builder;
    generate_a_part(result, result_builder, 0, 0);

    return result;
}

void AlternatingSortedArrays::generate_a_part(
    std::vector<std::string>& results,
    std::vector<int> result_builder,
    std::size_t a_index,
    std::size_t b_index
) {

    for (auto i = a_index; i < m_a.size(); ++i)
    {
        if (!result_builder.empty() && result_builder.back() > m_a[i]) {
            continue;
        }

        result_builder.push_back(m_a[i]);
        generate_b_part(results, result_builder, i + 1, b_index);
        result_builder.pop_back();
    }
}

void AlternatingSortedArrays::generate_b_part(
    std::vector<std::string>& results,
    std::vector<int> result_builder,
    std::size_t a_index,
    std::size_t b_index
) {

    for (auto i = b_index; i < m_b.size(); ++i)
    {
        if (result_builder.back() > m_b[i]) {
            continue;
        }

        result_builder.push_back(m_b[i]);
        results.push_back(to_string(result_builder));
        generate_a_part(results, result_builder, a_index, i + 1);
        result_builder.pop_back();
    }
}