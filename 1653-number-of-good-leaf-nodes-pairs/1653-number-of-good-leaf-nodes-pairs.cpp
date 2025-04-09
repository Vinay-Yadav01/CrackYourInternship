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
    vector<int> solve(TreeNode* root, int distance, int& cnt) {
        if (root == NULL)
            return {};
        if (root->left == NULL && root->right == NULL)
            return {1};
        vector<int> leftAns = solve(root->left, distance, cnt);
        vector<int> rightAns = solve(root->right, distance, cnt);
        for (int a : leftAns) {
            for (int b : rightAns) {
                if (a + b <= distance)
                    cnt++;
            }
        }
        vector<int> res;
        for (int a : leftAns) {
            if (a + 1 <= distance)
                res.push_back(a + 1);
        }
        for (int b : rightAns) {
            if (b + 1 <= distance)
                res.push_back(b + 1);
        }
        return res;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        solve(root, distance, cnt);
        return cnt;
    }
};