#include <iostream>
#include <vector>
#include <map>

class Solution {
    std::vector<std::vector<int>> m_solution;
    std::vector<int> m_current;
    std::map<int,int> m_unused_nums;

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        for (auto num : nums) {
            increment_used(num);
        }

        backtracking();

        return m_solution;
    }

    void backtracking() {
        if (m_unused_nums.empty()) {
            m_solution.emplace_back(m_current);
        }
        std::vector<int> candidates;
        for (auto it : m_unused_nums) {
            candidates.push_back(it.first);
        }
        for (int candidate : candidates) {
            m_current.push_back(candidate);
            decrement_used(candidate);
            backtracking();
            increment_used(candidate);
            m_current.pop_back();
        }
    }

    void decrement_used(const int& num) {
        int count = --m_unused_nums[num];
        if (count == 0) {
            m_unused_nums.erase(num);
        }
    }

    void increment_used(const int& num) {
        if (m_unused_nums.find(num) == m_unused_nums.end()) {
            m_unused_nums[num] = 1;
        } else {
            ++m_unused_nums[num];
        }
    }

    void printSolution()
        const
    {
        bool first = true;
        for (auto vec : m_solution) {
            if (first) first = false;
            else std::cout << ' ';
            printVec(vec);
        }
    }

private:
    void printVec(const std::vector<int>& vec)
        const
    {
        bool first = true;
        std::cout << '[';
        for (const int& i : vec) {
            if (first) first = false;
            else std::cout << ' ';
            std::cout << i;
        }
        std::cout << ']';
    }
};

int main() {
    Solution soln;
    std::vector<int> nums {1,1,2,2};
    soln.permuteUnique(nums);
    soln.printSolution();
};