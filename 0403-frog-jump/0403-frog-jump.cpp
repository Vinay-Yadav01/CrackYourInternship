class Solution {
    unordered_map<int, unordered_map<int, bool>> dp;

    bool solve(int pos, int jump, unordered_set<int>& stoneSet, int target) {
        if (pos == target) return true;
        if (!stoneSet.count(pos)) return false;
        if (dp[pos].count(jump)) return dp[pos][jump];

        for (int step = jump - 1; step <= jump + 1; ++step) {
            if (step > 0 && solve(pos + step, step, stoneSet, target))
                return dp[pos][jump] = true;
        }
        return dp[pos][jump] = false;
    }

public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false; // First jump must be 1
        unordered_set<int> stoneSet(stones.begin(), stones.end());
        int target = stones.back();
        return solve(1, 1, stoneSet, target); // Start at position 1 with step 1
    }
};
