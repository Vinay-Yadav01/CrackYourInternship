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
    void solve(TreeNode* root, int curSum, int targetSum, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            temp.push_back(root->val);
            curSum += root->val;
            if (curSum == targetSum)
                ans.push_back(temp);
            temp.pop_back();
            curSum += root->val;
            return;
        }
        temp.push_back(root->val);
        curSum += root->val;
        solve(root->left, curSum, targetSum, temp, ans);
        solve(root->right, curSum, targetSum, temp, ans);
        temp.pop_back();
        curSum += root->val;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int curSum = 0;
        solve(root, curSum, targetSum, temp, ans);
        return ans;
    }
};