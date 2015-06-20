#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    std::stack<int> m_stack;

public:
    void push(int x) {
        if (m_stack.empty()) {
            m_stack.push(x);
            m_stack.push(x);
            return;
        }

        int min = m_stack.top();
        m_stack.push(x);
        if (x < min) {
            m_stack.push(x);
        } else {
            m_stack.push(min);
        }
    }

    void pop() {
        m_stack.pop();
        m_stack.pop();
    }

    int top() {
        int min = m_stack.top();
        m_stack.pop();
        int top = m_stack.top();
        m_stack.push(min);
        return top;
    }

    int getMin() {
        return m_stack.top();
    }
};

int main()
{
    MinStack ms;
    ms.push(10);
    ms.push(5);
    ms.push(111);
    ms.push(11);
    std::cout << "Top: " << ms.top() << std::endl;
    std::cout << "Min: " << ms.getMin() << std::endl;
    ms.pop();
    std::cout << "Top: " << ms.top() << std::endl;
    std::cout << "Min: " << ms.getMin() << std::endl;
}