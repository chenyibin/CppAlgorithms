#ifndef MEDIUMPROBLEMSET_TREE_NODE_H
#define MEDIUMPROBLEMSET_TREE_NODE_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    :val(x)
    ,left(nullptr)
    ,right(nullptr)
    { }

    ~TreeNode()
    {
        if (left != nullptr) {
            delete left;
        }
        if (right != nullptr) {
            delete right;
        }
    }
};


#endif //MEDIUMPROBLEMSET_TREE_NODE_H
