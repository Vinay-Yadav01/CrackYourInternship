class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> loseCount;
        set<int> noLost;
        for (auto match : matches) {
            int winner = match[0], loser = match[1];
            if (noLost.find(loser) != noLost.end())
                noLost.erase(loser);
            if (loseCount[winner] == 0)
                noLost.insert(winner);
            loseCount[loser]++;
        }
        vector<vector<int>> res;
        vector<int> temp(noLost.begin(), noLost.end());
        res.push_back(temp);
        temp.clear();
        for (auto it : loseCount) {
            if (it.second == 1)
                temp.push_back(it.first);
        }
        res.push_back(temp);
        return res;
    }
};