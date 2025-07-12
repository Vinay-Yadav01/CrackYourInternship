class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> freq;
        for (int p : power)
            freq[p] += p;  // Store total damage, not just frequency

        vector<long long> unique;
        for (auto& [val, sum] : freq)
            unique.push_back(val);

        sort(unique.begin(), unique.end());

        int n = unique.size();
        vector<long long> dp(n);

        for (int i = 0; i < n; ++i) {
            long long curr = freq[unique[i]];

            // Find last index j such that unique[j] <= unique[i] - 3
            int j = i - 1;
            while (j >= 0 && unique[j] >= unique[i] - 2)
                j--;

            long long include = curr + (j >= 0 ? dp[j] : 0);
            long long exclude = (i > 0 ? dp[i - 1] : 0);
            dp[i] = max(include, exclude);
        }

        return dp[n - 1];
    }
};
