class Solution {
    void dfs(int ind, int n, vector<int>& temp, vector<vector<int>>& ans,
             vector<vector<int>>& graph) {
        if (ind == n - 1) {
            temp.push_back(ind);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(ind);
        for (int it : graph[ind]) {
            dfs(it, n, temp, ans, graph);
        }
        temp.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, n, temp, ans, graph);
        return ans;
    }
};