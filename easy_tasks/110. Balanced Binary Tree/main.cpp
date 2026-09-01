#include <limits>
#include <algorithm>

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
    int getRootDepth(TreeNode* root, int current_depth)
    {
        if (!root)
        {
            return current_depth;
        }

        current_depth++;
        if (!root->left && !root->right)
        {
            return current_depth;
        }
        int left_node_depth = getRootDepth(root->left, current_depth); 
        int right_node_depth = getRootDepth(root->right, current_depth);
        if (std::abs(right_node_depth - left_node_depth) > 1) // in case difference between subtree depths is more than 1, give it highest maximal value to signal it is unbalanced and propagate it further
        {
            return std::numeric_limits<int>::max();
        } 
        return std::max(left_node_depth, right_node_depth); // current node is as deep as it's furthest child - if one of the branches has max depth (highest int number), then that value should also get propagated to the root
    }
    bool isBalanced(TreeNode* root) {
        return getRootDepth(root, 0) < std::numeric_limits<int>::max();
    }
};