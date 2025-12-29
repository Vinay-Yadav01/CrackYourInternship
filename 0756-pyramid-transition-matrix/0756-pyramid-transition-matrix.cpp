class Solution {
    bool solve(string bottom, string curr, int row, int col,
               unordered_set<string>& allowedSet,
               unordered_map<string, bool>& dp) {

        if (row == 1)
            return true;

        string key = bottom + "|" + curr;
        if (dp.count(key))
            return dp[key];

        if (curr.size() == row - 1)
            return dp[key] = solve(curr, "", row - 1, 0, allowedSet, dp);

        for (char ch = 'A'; ch <= 'F'; ch++) {
            string pattern;
            pattern += bottom[col];
            pattern += bottom[col + 1];
            pattern += ch;

            if (allowedSet.count(pattern)) {
                if (solve(bottom, curr + ch, row, col + 1, allowedSet, dp))
                    return dp[key] = true;
            }
        }

        return dp[key] = false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string> allowedSet(allowed.begin(), allowed.end());
        unordered_map<string, bool> dp;
        return solve(bottom, "", bottom.size(), 0, allowedSet, dp);
    }
};
