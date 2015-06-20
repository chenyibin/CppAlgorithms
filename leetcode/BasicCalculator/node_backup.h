#ifndef BASICCALCULATOR_NODE_BACKUP_H
#define BASICCALCULATOR_NODE_BACKUP_H

#include <vector>
#include <string>

enum NodeType {
    PLUS,
    MINUS,
    EXPR,
    NUM,
    NONE
};

/**
 * Implementation using a simple parse tree with tree generation and
 * evaluations separated. This isn't as fast as the direct recursive approach.
 * However, it's easier to debug and more extensible.
 */
class Node {
    std::vector<Node> m_children;
    NodeType m_type;
    // if the node is of type NUM, store the number
    // if the node is of type EXPR, store the end of the expression
    int m_num;

public:

    Node(const std::string& s, size_t start)
        : m_children{}
        , m_type{EXPR}
        , m_num{0}
    {
        std::string num = "";
        size_t i;
        for (i = start; i < s.size(); ++i)
        {
            char c = s[i];
            if (is_num(c)) {
                num += c;
                continue;
            } else if (!num.empty()) {
                m_children.emplace_back(Node(std::stoi(num)));
                num = "";
            }
            if (is_op(c)) {
                m_children.emplace_back(Node(c));
            } else if (c == ')') {
                // end of this expression
                break;
            } else if (c == '(') {
                m_children.emplace_back(Node(s, i+1));
                i = m_children.back().m_num;
            }
        }

        if (!num.empty()) {
            m_children.emplace_back(Node(std::stoi(num)));
        }
        m_num = i;
    }

    Node(char c)
        : m_children{}
        , m_num{0}
    {
        if (c == '-') {
            m_type = MINUS;
        } else if (c == '+') {
            m_type = PLUS;
        }
    }

    Node(int num)
        : m_children{}
        , m_type{NUM}
        , m_num{num}
    { }

    int evaluate() const
    {
        int result = 0;
        NodeType lastType = NONE;
        for (const Node& child : m_children) {
            if (child.m_type == NUM || child.m_type == EXPR)
            {
                int cur_num = child.m_num;
                if (child.m_type == EXPR) {
                    cur_num = child.evaluate();
                }

                if (lastType == NONE) {
                    result = cur_num;
                } else if (lastType == MINUS) {
                    result -= cur_num;
                } else if (lastType == PLUS) {
                    result += cur_num;
                }
            }
            lastType = child.m_type;
        }
        return result;
    }

    static bool is_num(char& c)
    {
        return (c >= '0') && (c <= '9');
    }

    static bool is_op(char& c)
    {
        return (c == '-') || (c == '+');
    }
};
#endif //BASICCALCULATOR_NODE_BACKUP_H
