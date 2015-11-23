#include <iostream>

class Solution {

    std::string m_num;
public:

    bool isAdditiveNumber(std::string num) {
        m_num = num;
        size_t num_length = m_num.length();
        if (num_length < 3) {
            return false;
        }

        // Since we are only summing positive numbers
        size_t term1_max_length = (num_length-1)/2;
        // If the number string starts with 0, the the first number can only be 0
        if (m_num[0] == '0') {
            term1_max_length = 1;
        }

        for (size_t term1_end = 1; term1_end <= term1_max_length; ++term1_end)
        {
            size_t remainder_length = num_length - term1_end;
            size_t term2_max_length = std::min(remainder_length/2, remainder_length - term1_end);
            for (size_t term2_end = term1_end + 1; term2_end <= term1_end + term2_max_length; ++term2_end)
            {
                if (isAdditiveSequence(term1_end, term2_end))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool isAdditiveSequence(
        size_t term1_end,
        size_t term2_end
    ) const {
        long term1 = substrToLong(0, term1_end);
        long term2 = substrToLong(term1_end, term2_end-term1_end);
        // Don't accept terms that begin with 0
        if (term2 > 9 && m_num[term1_end] == '0') {
            return false;
        }

        while (term2_end < m_num.length()) {
            long sum = term1 + term2;
            std::string sum_str = std::to_string(sum);

            // Sanity check that the length of the sum string
            // still fits the remainder of m_num
            size_t sum_end = term2_end + sum_str.length();
            if (sum_end > m_num.length()) {
                return false;
            }

            // If checked string starts with '0' or
            // doesn't match the expected sum return false
            std::string checked_sum = m_num.substr(term2_end, sum_str.length());
            if (checked_sum[0] == '0' || checked_sum != sum_str) {
                return false;
            }

            // Advance to next check
            term2_end = sum_end;
            term1 = term2;
            term2 = sum;
        }
        return true;
    }

    long substrToLong(
        const size_t& pos,
        const size_t& count
    ) const {
        std::string num_str = m_num.substr(pos, count);
        return std::stol(num_str);
    }
};

int main() {
    Solution solution;
    std::cout << solution.isAdditiveNumber("120122436") << std::endl;
    return 0;
}