class Solution {
    vector<int> dp;

    int solve(int i, vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int width = 0, height = 0, ans = INT_MAX;

        for (int j = i; j < n; ++j) {
            width += books[j][0];
            if (width > shelfWidth) break;

            height = max(height, books[j][1]);
            ans = min(ans, height + solve(j + 1, books, shelfWidth));
        }

        return dp[i] = ans;
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        dp = vector<int>(n, -1);
        return solve(0, books, shelfWidth);
    }
};
