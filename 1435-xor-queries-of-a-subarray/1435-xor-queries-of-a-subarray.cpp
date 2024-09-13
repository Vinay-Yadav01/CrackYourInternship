class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i] ^ arr[i - 1];
        }
        vector<int> ans;
        for (auto querie : queries) {
            int left = querie[0];
            int right = querie[1];
            int temp = arr[right];
            if (left > 0)
                temp ^= arr[left - 1];
            ans.push_back(temp);
        }
        return ans;
    }
};