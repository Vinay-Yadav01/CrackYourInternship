class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int champTeam = -1, maxWeakTeamCount = -1;
        for (int i=0;i<grid.size();i++) {
            int weakTeamCount = 0;
            for (auto j : grid[i]) {
                weakTeamCount += j;
            }
            if (weakTeamCount > maxWeakTeamCount) {
                maxWeakTeamCount = weakTeamCount;
                champTeam = i;
            }
        }
        return champTeam;
    }
};