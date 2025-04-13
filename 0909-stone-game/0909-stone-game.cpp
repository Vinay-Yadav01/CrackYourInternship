class Solution {
    int aliceCount = 0;
    int bobCount = 0;
    bool f(int i, int j, int turn, vector<int>& piles,
           vector<vector<vector<int>>>& dp) {
        if (i == j) {
            if (turn == 0)
                aliceCount += piles[i];
            else
                bobCount += piles[i];
            return aliceCount > bobCount;
        }
        if (dp[i][j][turn] != -1)
            return dp[i][j][turn];
        if (turn) {
            // Option 1
            aliceCount += piles[i];
            int op1 = f(i + 1, j, 1, piles, dp);
            aliceCount -= piles[i];
            // Options 2
            aliceCount += piles[j];
            int op2 = f(i, j - 1, 1, piles, dp);
            aliceCount -= piles[j];
            return dp[i][j][turn] = op1 || op2;
        } else {
            // Option 1
            bobCount += piles[i];
            int op1 = f(i + 1, j, 0, piles, dp);
            bobCount -= piles[i];
            // Options 2
            bobCount += piles[j];
            int op2 = f(i, j - 1, 0, piles, dp);
            bobCount -= piles[j];
            return dp[i][j][turn] = op1 || op2;
        }
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int turn = 0; // 0->Alice , 1->Bob
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, -1)));
        return f(0, n - 1, turn, piles, dp);
    }
};