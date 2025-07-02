class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        long long result = 0, currentSum = 0;

        // Case 1: The chosen k-length segment starts at coins[i][0]
        for (int i = 0, j = 0; i < n; i++) {

            while (j < n && coins[j][1] <= coins[i][0] + k - 1) {
                currentSum +=
                    (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            if (j < n) {
                long long partial =
                    (long long)max(0, coins[i][0] + k - 1 - coins[j][0] + 1) *
                    coins[j][2];
                result = max(result, currentSum + partial);
            }

            currentSum -=
                (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        // Case 2: The chosen k-length segment ends at coins[i][1]
        currentSum = 0;
        for (int i = 0, j = 0; i < n; i++) {
            currentSum +=
                (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];

            while (coins[j][1] < coins[i][1] - k + 1) {
                currentSum -=
                    (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            long long partial =
                (long long)max(0, coins[i][1] - k - coins[j][0] + 1) *
                coins[j][2];
            result = max(result, currentSum - partial);
        }

        return result;
    }
};
