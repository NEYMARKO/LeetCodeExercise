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
    void traverseDFS(std::vector<int>& result, TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        result.push_back(root->val);
        if (root->left)
        traverseDFS(result, root->left);
        traverseDFS(result, root->right);
    }
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverseDFS(result, root);
        return result;
    }
};