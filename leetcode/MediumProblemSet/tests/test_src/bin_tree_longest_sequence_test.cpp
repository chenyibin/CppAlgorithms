#include "gtest/gtest.h"

#include "bin_tree_longest_sequence.h"
#include "serialize_bin_tree.h"

TEST(tree_longest_sequence_test, test_one_path)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);

    BinTreeLongestSequence solver;
    int longest = solver.longestConsecutive(root);
    ASSERT_EQ(3, longest);
    delete(root);
}

TEST(tree_longest_sequence_test, test_lower_path)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);

    BinTreeLongestSequence solver;
    int longest = solver.longestConsecutive(root);
    ASSERT_EQ(2, longest);
    delete(root);
}


TEST(tree_longest_sequence_test, test_two_equal_paths)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(8);

    BinTreeLongestSequence solver;
    int longest = solver.longestConsecutive(root);
    ASSERT_EQ(2, longest);
    delete(root);
}


