class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        
        // Step 1: Sort each cuboid's dimensions
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        // Step 2: Sort all cuboids
        sort(cuboids.begin(), cuboids.end());

        // Step 3: Apply LIS-like DP
        vector<int> dp(n);
        int maxHeight = 0;

        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][2];  // base height
            for (int j = 0; j < i; ++j) {
                if (cuboids[i][0] >= cuboids[j][0] &&
                    cuboids[i][1] >= cuboids[j][1] &&
                    cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]); 
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;
    }
};
