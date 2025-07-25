/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int solve(Node* root){
        if(!root) return 0;
        int maxi = 0;
        for(auto child: root->children){
            maxi = max(maxi, solve(child));
        }
        return 1 + maxi;
    }
public:
    int maxDepth(Node* root) {
        return solve(root);
    }
};