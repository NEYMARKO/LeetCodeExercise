#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    /**void traversePostorder(std::vector<int>& result, TreeNode*& root) // passing reference to the address so that I could actually modify what root is pointing to
                                                                    // addresses are getting passsed by value, which means that only local value of root (the one in the function)
                                                                    // will get modified, but not the pointer that has been passed as an argument
    {
        if (!root)
        {
            return;
        }
        traversePostorder(result, root->left);
        traversePostorder(result, root->right);
        if (!root->left && !root->right)
        {
            result.push_back(root->val);
        }
        root = nullptr;
    }*/
    void traversePostorder(std::vector<int>& result, TreeNode*& root) // this version does not modify original tree, which makes it more correct
    {
        if (!root)
        {
            return;
        }
        traversePostorder(result, root->left);
        traversePostorder(result, root->right);
        result.push_back(root->val);
    }
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traversePostorder(result, root);
        return result;
    }
};