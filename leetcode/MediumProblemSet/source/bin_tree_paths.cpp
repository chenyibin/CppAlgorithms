#include "bin_tree_paths.h"

std::vector<std::string> BinTreePaths::binaryTreePaths(TreeNode* root)
{
    m_solution.clear();
    if (root != nullptr) {
        recurse("", root);
    }
    return m_solution;
}

void BinTreePaths::recurse(const std::string& prefix, TreeNode* node)
{
    std::string new_prefix = prefix;
    new_prefix += std::to_string(node->val);

    if (node->left == nullptr && node->right == nullptr) {
        m_solution.push_back(new_prefix);
        return;
    }
    new_prefix += "->";
    if (node->left != nullptr) {
        recurse(new_prefix, node->left);
    }
    if (node->right != nullptr) {
        recurse(new_prefix, node->right);
    }
}
