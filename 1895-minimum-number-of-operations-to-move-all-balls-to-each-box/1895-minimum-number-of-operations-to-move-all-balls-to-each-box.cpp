class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int jumps = 0;
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '1') {
                    jumps += abs(i - j);
                    // cout << i << " " << j << endl;
                }
            }
            ans[i] = jumps;
        }
        return ans;
    }
};