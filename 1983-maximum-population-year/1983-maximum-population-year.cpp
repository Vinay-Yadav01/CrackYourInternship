class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        for (auto log : logs) {
            int startYear = log[0], endYear = log[1];
            mp[startYear]++;
            mp[endYear]--;
        }

        int maxPopulation = 0, currPopulation = 0, maxYear;
        for (auto& [year, val] : mp) {
            currPopulation += val;
            if(maxPopulation < currPopulation){
                maxPopulation = currPopulation;
                maxYear = year;
            }
        }
        return maxYear;
    }
};