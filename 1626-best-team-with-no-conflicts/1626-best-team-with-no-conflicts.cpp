class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> arr(n);

        for (int i = 0; i < n; i++)
            arr[i] = {ages[i], scores[i]};

        // Sort by age asc, and for same age by score asc
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        vector<int> dp(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = arr[i].second;  
            for (int j = 0; j < i; j++) {
                if (arr[j].second <= arr[i].second) { 
                    dp[i] = max(dp[i], dp[j] + arr[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
