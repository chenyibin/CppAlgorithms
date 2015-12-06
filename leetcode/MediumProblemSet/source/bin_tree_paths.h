#include <vector>
#include <string>

#include "tree_node.h"

#ifndef MEDIUMPROBLEMSET_BIN_TREE_PATHS_H
#define MEDIUMPROBLEMSET_BIN_TREE_PATHS_H

class BinTreePaths {

    std::vector<std::string> m_solution;

public:

    /**
     * Returns all the paths from root to leaf
     * in the format "1->4->3" where each number is the
     * val stored in the TreeNode
     */
    std::vector<std::string> binaryTreePaths(TreeNode* root);

private:

    /**
     * Using recursion here since it's easier to write and the
     * implementation for this problem is pretty straightforward.
     */
    void recurse(const std::string& prefix, TreeNode* node);

};
#endif //MEDIUMPROBLEMSET_BIN_TREE_PATHS_H
