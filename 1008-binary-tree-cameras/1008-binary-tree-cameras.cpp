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
    // Three Cases:
    // 0 -> No Camera and Not Monitoring
    // 1 -> No Camera and Monitoring
    // 2 -> Camera and Monitoring

    int solve(TreeNode* root, int& cameraCount) {
        if (root == NULL)
            return 1;
        int left = solve(root->left, cameraCount);
        int right = solve(root->right, cameraCount);
        if (left == 0 || right == 0) {
            cameraCount++;
            return 2; // Required to install Camera
        }
        if (left == 2 || right == 2)
            return 1; // Already monitoring, no need to install camera
        return 0; // Either or both of them is 1, therefore it is not monitoring
                  // but its child are monitored
    }

public:
    int minCameraCover(TreeNode* root) {
        int cameraCount = 0;
        if (solve(root, cameraCount) == 0)
            cameraCount++; // Place camera at root if needed
        return cameraCount;
    }
};