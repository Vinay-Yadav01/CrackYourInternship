class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1])
                prefix[i] = prefix[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1])
                suffix[i] = suffix[i + 1] + 1;
        }
        vector<int> ans;
        for (int i = k; i < n-k; i++) {
            cout<<prefix[i]<<" "<<nums[i]<<" "<<suffix[i]<<endl;
            if (prefix[i-1] >= k && suffix[i+1] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};