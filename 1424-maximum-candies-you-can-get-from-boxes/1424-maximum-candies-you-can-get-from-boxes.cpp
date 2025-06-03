class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();

        // Apply BFS from start points: Multi-Source BFS (DAG: Since Box-A
        // inside Box-B then opposite is NOT True)
        queue<int> q;
        for (int start : initialBoxes)
            q.push(start);

        unordered_set<int> closed;
        int total = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // If current box is closed then save it for possible later opening
            // (by finding key)
            if (status[curr] == 0) {
                closed.insert(curr);
                continue;
            }

            // Current box is open. Let's open the closed boxes (if any)
            for (int open : keys[curr]) {
                status[open] = 1;
                if (closed.count(open)) {
                    q.push(open);
                    closed.erase(open);
                }
            }

            // Add value and store adjacent nodes
            total += candies[curr];
            for (int nbr : containedBoxes[curr])
                q.push(nbr);
        }
        return total;
    }
};