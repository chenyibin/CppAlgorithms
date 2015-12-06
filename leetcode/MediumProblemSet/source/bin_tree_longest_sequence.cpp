#include <algorithm>

#include "bin_tree_longest_sequence.h"

int BinTreeLongestSequence::longestConsecutive(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }

    return recurseLongestSequence(root, nullptr, 0);
}

int BinTreeLongestSequence::recurseLongestSequence(
    const TreeNode* node,
    const TreeNode* parent,
    int sequence_length
) {
    if (node == nullptr) {
        return sequence_length;
    }

    if (parent != nullptr && node->val == parent->val + 1) {
        ++sequence_length;
    } else {
        sequence_length = 1;
    }
    int max_child_sequence_length = std::max(
        recurseLongestSequence(node->left, node, sequence_length),
        recurseLongestSequence(node->right, node, sequence_length)
    );

    return std::max(sequence_length, max_child_sequence_length);
}
