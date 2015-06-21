#include <iostream>
#include <vector>

class Solution {

    std::vector<std::vector<int>> m_solution;
    std::vector<int> m_current;
public:
    Solution()
        : m_solution {}
        , m_current {}
    { }

    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        comboSeeker(k, n);
        return m_solution;
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

    void comboSeeker(int nums, int sum) {
        if (nums > sum || sum < 0) {
            return;
        }
        if (nums == 0) {
            if (sum == 0) {
                m_solution.emplace_back(m_current);
            }
            return;
        }

        int start = 1;
        if (!m_current.empty()) {
            start = m_current.back() + 1;
        }

        for (int i = start; i < 10; ++i) {
            m_current.emplace_back(i);
            comboSeeker(nums - 1, sum - i);
            m_current.pop_back();
        }
    }
};


int main() {
    Solution soln;
    soln.combinationSum3(3, 9);
    soln.printSolution();
    return 0;
}