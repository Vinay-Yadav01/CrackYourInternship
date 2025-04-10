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
            if (indegree[i] == 0) {
                if (champTeam != -1) {
                    return -1; // More than one team with in-degree 0
                }
                champTeam = i;
            }
        }
        return champTeam;
    }
};