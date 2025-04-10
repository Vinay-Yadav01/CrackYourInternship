class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto it : edges) {
            int v = it[1];
            indegree[v]++;
        }
        int champTeam = -1;
        for (int i = 0; i < n; i++) {
            if (champTeam != -1 && indegree[i] == 0)
                return -1;
            if (indegree[i] == 0)
                champTeam = i;
        }
        return champTeam;
    }
};