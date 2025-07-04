class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int mod = 1e9+7;
        unordered_map<int, unordered_map<int, int>> adj;
        for (auto& conv : conversions) {
            int u = conv[0], v = conv[1], wt = conv[2];
            adj[u][v] = wt;
        }
        int n = conversions.size();
        vector<long long> res(n + 1, -1);
        queue<int> q;
        res[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& [nbr, wt] : adj[curr]) {
                res[nbr] = ((long long)res[curr] * wt)%mod;
                q.push(nbr);
            }
        }
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i] = (int)res[i];
        }
        return ans;
    }
};
