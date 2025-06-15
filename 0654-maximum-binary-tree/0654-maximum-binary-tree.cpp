/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    pair<int, int> maxElement(vector<int>& nums, int left, int right) {
        int ind = -1, maxi = INT_MIN;
        for (int i = left; i <= right; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                ind = i;
            }
        }
        return {maxi, ind};
    }
    TreeNode* solve(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;
        auto [maxValue, ind] =  maxElement(nums, left, right);
        TreeNode* node = new TreeNode(maxValue);
        node->left = solve(nums, left, ind - 1);
        node->right = solve(nums, ind + 1, right);
        return node;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        return solve(nums, left, right);
    }
};