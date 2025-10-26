class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(),
             [k](const vector<int>& s1, const vector<int>& s2) {
                 return s1[k] >= s2[k];
             });
        return score;
    }
};