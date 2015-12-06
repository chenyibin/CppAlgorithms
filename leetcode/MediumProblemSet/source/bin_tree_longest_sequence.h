#include "tree_node.h"

#ifndef MEDIUMPROBLEMSET_BIN_TREE_LONGEST_SEQUENCE_H
#define MEDIUMPROBLEMSET_BIN_TREE_LONGEST_SEQUENCE_H

class BinTreeLongestSequence {

public:

    /**
     * Get the longest series of consecutive values in a subtree
     */
    int longestConsecutive(TreeNode* root);

private:

    int recurseLongestSequence(
        const TreeNode* node,
        const TreeNode* parent,
        int sequence_length
    );
};

#endif //MEDIUMPROBLEMSET_BIN_TREE_LONGEST_SEQUENCE_H
