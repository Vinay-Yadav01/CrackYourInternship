class TrieNode {
    TrieNode* links[2];

public:
    TrieNode() { links[0] = links[1] = nullptr; }
    bool containKey(int bit) { return links[bit] != nullptr; }
    void put(int key) { links[key] = new TrieNode(); }
    TrieNode* get(int bit) { return links[bit]; }
};

class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit)) {
                node->put(bit);
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        TrieNode* node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containKey(!bit)) {
                maxi = maxi | (1 << i); // For maximum value we want all bit to
                                        // 1
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ;
        int q = queries.size();
        for (int i = 0; i < q; i++) {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oQ.begin(), oQ.end());
        int ind = 0;
        int n = nums.size();
        vector<int> ans(q, 0);
        Trie trie;
        for (int i = 0; i < q; i++) {
            int mi = oQ[i].first;
            int xi = oQ[i].second.first;
            int index = oQ[i].second.second;
            while (ind < n && nums[ind] <= mi) {
                trie.insert(nums[ind]);
                ind++;
            }
            if (ind == 0)
                ans[index] = -1;
            else
                ans[index] = trie.getMax(xi);
        }
        return ans;
    }
};