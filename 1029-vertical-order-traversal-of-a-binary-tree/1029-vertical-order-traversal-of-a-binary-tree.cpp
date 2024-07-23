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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> mp;
        queue<pair<int, pair<int, TreeNode*>>> q;
        q.push({0, {0, root}});
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int hd = temp.first;
            int level = temp.second.first;
            TreeNode* node = temp.second.second;
            if (mp[hd].find(level) != mp[hd].end()) {
                mp[hd][level].push_back(node->val);
                sort(mp[hd][level].begin(),mp[hd][level].end());                    
            } else
                mp[hd][level].push_back(node->val);
            if (node->left)
                q.push({hd - 1, {level + 1, node->left}});
            if (node->right)
                q.push({hd + 1, {level + 1, node->right}});
        }
        for (auto i : mp) {
            vector<int> temp;
            for (auto j : i.second) {
                for (auto k : j.second) {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};