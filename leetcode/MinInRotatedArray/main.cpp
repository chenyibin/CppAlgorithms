#include <iostream>
#include <vector>

class Solution
{
public:

    int findMin(std::vector<int>& nums)
    {
        size_t lo = 0, hi = nums.size() - 1;

        while (true)
        {
            if (hi == lo) {
                return nums[hi];
            }
            if (hi - lo == 1 && (nums[lo] > nums[hi])) {
                return nums[hi];
            }
            int mid = (lo + hi) / 2;
            if (nums[hi] < nums[mid]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
    }
};

void printArray(std::vector<int>& nums)
{
    std::string result {""};
    bool first = true;
    for (auto num : nums)
    {
        if (first) first = false;
        else std::cout << " ";
        std::cout << num;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> test_case {1,2,3};
    printArray(test_case);
    Solution solution;
    int min = solution.findMin(test_case);
    std::cout << "Min: " << min << std::endl;
}