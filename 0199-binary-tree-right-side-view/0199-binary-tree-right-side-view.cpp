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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<pair<int,TreeNode*>> q;
        q.push({1,root});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int level = temp.first;
            TreeNode* front = temp.second;
            if(level>ans.size()) ans.push_back(front->val);
            if(front->right) q.push({level+1,front->right});
            if(front->left) q.push({level+1,front->left});
        }
        return ans;
    }
};