#include <string>

#include "tree_node.h"

#ifndef MEDIUMPROBLEMSET_SERIALIZE_BIN_TREE_H
#define MEDIUMPROBLEMSET_SERIALIZE_BIN_TREE_H

class SerializeBinTree
{
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data);

private:
    static void serialize_to_string(std::string& result, TreeNode* node);
};
#endif //MEDIUMPROBLEMSET_SERIALIZE_BIN_TREE_H
