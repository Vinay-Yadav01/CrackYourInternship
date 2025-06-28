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

class Values {
public:
    int low, high;
    TreeNode* parent;
    bool isLeft;
    Values() : low(0), high(0), parent(nullptr), isLeft(true) {}
    Values(int low, int high, TreeNode* parent, bool isLeft) {
        this->low = low;
        this->high = high;
        this->parent = parent;
        this->isLeft = isLeft;
    }
};

class Solution {
    bool isValidBST(TreeNode* root, long long low = LLONG_MIN, long long high = LLONG_MAX) {
        if (!root) return true;
        if (root->val <= low || root->val >= high) return false;
        return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_set<int> isChild;
        unordered_map<int, TreeNode*> treeMap;

        // Map roots and mark all children
        for (auto tree : trees) {
            treeMap[tree->val] = tree;
            if (tree->left) isChild.insert(tree->left->val);
            if (tree->right) isChild.insert(tree->right->val);
        }

        // Find the main root (not a child)
        TreeNode* root = nullptr;
        for (auto tree : trees) {
            if (!isChild.count(tree->val)) {
                root = tree;
                break;
            }
        }

        if (!root) return nullptr;

        treeMap.erase(root->val);
        unordered_map<int, Values> curLeaves;

        if (root->left)
            curLeaves[root->left->val] = Values(INT_MIN, root->val, root, true);
        if (root->right)
            curLeaves[root->right->val] = Values(root->val, INT_MAX, root, false);

        while (!treeMap.empty()) {
            bool found = false;

            for (auto it = curLeaves.begin(); it != curLeaves.end(); ++it) {
                int leafVal = it->first;
                Values val = it->second;

                if (treeMap.find(leafVal) == treeMap.end()) continue;

                TreeNode* newTree = treeMap[leafVal];
                treeMap.erase(leafVal);
                curLeaves.erase(leafVal);

                // Check left child of newTree
                if (newTree->left) {
                    int v = newTree->left->val;
                    if (v <= val.low || v >= newTree->val) return nullptr;
                    curLeaves[v] = Values(val.low, newTree->val, newTree, true);
                }

                // Check right child of newTree
                if (newTree->right) {
                    int v = newTree->right->val;
                    if (v <= newTree->val || v >= val.high) return nullptr;
                    curLeaves[v] = Values(newTree->val, val.high, newTree, false);
                }

                // Attach newTree to its parent
                if (val.isLeft)
                    val.parent->left = newTree;
                else
                    val.parent->right = newTree;

                found = true;
                break;
            }

            if (!found) return nullptr;
        }

        // Final validation of BST
        if (!isValidBST(root)) return nullptr;

        return root;
    }
};
