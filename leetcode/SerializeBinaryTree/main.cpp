#include <iostream>
#include <sstream>
#include <stack>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root) {
        if (root == nullptr){
            return "~";
        }

        std::string result;
        serialize_to_string(result, root);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
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

private:
    static void serialize_to_string(std::string& result, TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        result.append(std::to_string(node->val) + "{");
        serialize_to_string(result, node->left);
        result.push_back(',');
        serialize_to_string(result, node->right);
        result.push_back('}');

    }
};

int main() {

    std::string sample = "2{3{,},4{,}}";
    Codec stuffs;
    TreeNode* node = stuffs.deserialize(sample);
    std::cout << stuffs.serialize(node) << std::endl;
    return 0;
}