/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

class Solution {
public:
    TreeNode* generateNode(int left_idx, int right_idx, vector<int>& nums)
    {
        if (left_idx > right_idx)
        {
            return nullptr;
        }

        int middle_idx = (int)((left_idx + right_idx) / 2);
        return new TreeNode(nums[middle_idx], generateNode(left_idx, middle_idx - 1, nums), generateNode(middle_idx + 1, right_idx, nums));
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return generateNode(0, nums.size() - 1, nums);
    }
};