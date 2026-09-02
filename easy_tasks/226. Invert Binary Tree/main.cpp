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
    void invertNode(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        
        if (!root->left && !root->right)
        {
            return;
        }
        
        // Go as low as possible to get to the level of smallest subtree - just 2 leaf nodes - invert them and climb one level up
        // do that on each side starting from root
        invertNode(root->left); // using recursion to get to the bottom => subtree needs to be inverted before inverting relationship between
                                // 2 subtrees. get to the bottom of the tree, invert leaf nodes there, then go 1 level up, invert nodes on that level, after that go up and repeat
        invertNode(root->right);
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        invertNode(root);
        return root;
    }
};