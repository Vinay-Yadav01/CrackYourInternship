class Solution {
    int bestDiff = INT_MAX; 
    vector<int> bestSet;

    void dfs(int idx, long long prod, int picked, int n, int k,
             vector<int>& div, vector<int>& path) {
        if (picked > k || prod > n) return;

        if (picked == k && prod == n) {
            int mx = *max_element(path.begin(), path.end());
            int mn = *min_element(path.begin(), path.end());
            int diff = mx - mn;

            if (diff < bestDiff) {
                bestDiff = diff;
                bestSet = path;
            }
            return;
        }

        for (int i = idx; i < div.size(); i++) {
            if (prod * div[i] > n) break; 
            
            path.push_back(div[i]);
            dfs(i, prod * div[i], picked + 1, n, k, div, path);
            path.pop_back();
        }
    }

public:
    vector<int> minDifference(int n, int k) {
        vector<int> div;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);
                if (i * i != n) div.push_back(n / i);
            }
        }

        sort(div.begin(), div.end());
        vector<int> path;
        dfs(0, 1, 0, n, k, div, path);

        return bestSet;
    }
};
