#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    static const std::vector<std::string> letters_map;

    std::vector<std::string> m_combo;
    std::vector<size_t> m_indexes;

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }

        for (char c : digits) {
            size_t i = c - '0';
            m_combo.push_back(letters_map[i]);
            m_indexes.emplace_back(0);
        }

        bool done = false;
        while (!done)
        {
            result.emplace_back(build_combination());
            done = update_combination();
        }
        return result;
    }
private:

    std::string build_combination()
    {
        std::string one_combo;
        for (size_t i = 0; i < m_indexes.size(); ++i) {
            one_combo += m_combo[i][m_indexes[i]];
        }
        return one_combo;
    }

    bool update_combination()
    {
        bool carry = true;
        for (size_t i = 0; i < m_indexes.size() && carry; ++i) {
            int new_index = ++m_indexes[i];
            if (new_index < m_combo[i].size()) {
                carry = false;
            } else {
                m_indexes[i] = 0;
            }
        }
        return carry;
    }
};

const std::vector<std::string> Solution::letters_map
    {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printArray(std::vector<std::string>& list)
{
    std::string result {""};
    bool first = true;
    for (auto item : list)
    {
        if (first) first = false;
        else std::cout << " ";
        std::cout << item;
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;
    auto combos = solution.letterCombinations("348");
    printArray(combos);
    return 0;
}