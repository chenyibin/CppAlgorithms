#include <algorithm>

#include "gtest/gtest.h"

#include "tree_node.h"
#include "bin_tree_paths.h"

TEST(bin_tree_paths_test, test_one_path)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);

    BinTreePaths solver;
    std::vector<std::string> solution = solver.binaryTreePaths(root);
    ASSERT_TRUE(std::find(solution.begin(), solution.end(),
        "1->2->3") != solution.end());
    delete(root);
}

TEST(bin_tree_paths_test, test_two_paths)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);

    root->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    BinTreePaths solver;
    std::vector<std::string> solution = solver.binaryTreePaths(root);
    ASSERT_TRUE(std::find(solution.begin(), solution.end(),
        "1->2->3") != solution.end());
    ASSERT_TRUE(std::find(solution.begin(), solution.end(),
        "1->5->7") != solution.end());
    delete(root);
}