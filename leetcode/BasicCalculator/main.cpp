#include <iostream>
#include <vector>
using namespace std;

static bool is_num(char& c)
{
    return (c >= '0') && (c <= '9');
}

static void process_op(int& result, const char& op, const int& new_num)
{
    if (op == '-') {
        result -= new_num;
    } else if (op == '+') {
        result += new_num;
    } else if (op == '?') {
        result = new_num;
    }
}

class Solution {
    std::string m_s;

public:

    int recurse_eval(size_t& pos)
    {
        std::string num = "";
        char last_op = '?';
        int result = 0;

        for (; pos < m_s.size(); ++pos)
        {
            char c = m_s[pos];
            if (is_num(c)) {
                num += c;
                continue;
            } else if (!num.empty()) {
                int int_num = std::stoi(num);
                process_op(result, last_op, int_num);
                num = "";
            }

            if (c == '-') {
                last_op = '-';
            } else if (c == '+') {
                last_op = '+';
            } else if (c == ')') {
                // end of this expression
                break;
            } else if (c == '(') {
                int int_num = recurse_eval(++pos);
                process_op(result, last_op, int_num);
            }
        }

        if (!num.empty()) {
            int int_num = std::stoi(num);
            process_op(result, last_op, int_num);
        }
        return result;
    }

    int calculate(std::string s) {
        if (s.empty()) {
            return 0;
        }
        m_s = s;
        size_t pos = 0;
        return recurse_eval(pos);
    }
};


int main() {
    Solution sln;
    std::cout << sln.calculate("(12+(4+5+2)-3)+(6+8)") << std::endl;
}