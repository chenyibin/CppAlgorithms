#include <stack>

#include "serialize_bin_tree.h"

// Encodes a tree to a single string.
std::string SerializeBinTree::serialize(TreeNode *root)
{
    if (root == nullptr) {
        return "~";
    }

    std::string result;
    serialize_to_string(result, root);
    return result;
}

TreeNode* SerializeBinTree::deserialize(std::string data)
{
    if (data == "~") {
        return nullptr;
    }

    std::stack<TreeNode*> traversal_stack;

    std::string num("");
    char prev = '~';
    for (auto symbol : data) {
        if (symbol == '{') {
            int val = std::stoi(num);
            TreeNode* newNode = new TreeNode(val);
            traversal_stack.push(newNode);
            num.clear();
        } else if (symbol == ',') {
            if (prev != '{') {
                TreeNode *left = traversal_stack.top();
                traversal_stack.pop();
                traversal_stack.top()->left = left;
            }
        } else if (symbol == '}') {
            if (prev != ',') {
                TreeNode *right = traversal_stack.top();
                traversal_stack.pop();
                traversal_stack.top()->right = right;
            }
        } else {
            num.push_back(symbol);
        }
        prev = symbol;
    }
    return traversal_stack.top();
}

void SerializeBinTree::serialize_to_string(std::string& result, TreeNode* node)
{
    if (node == nullptr) {
        return;
    }
    result.append(std::to_string(node->val) + "{");
    serialize_to_string(result, node->left);
    result.push_back(',');
    serialize_to_string(result, node->right);
    result.push_back('}');

}