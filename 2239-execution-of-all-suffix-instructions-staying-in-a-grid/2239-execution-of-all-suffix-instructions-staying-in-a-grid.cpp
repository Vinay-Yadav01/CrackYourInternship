class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        unordered_map<char, pair<int, int>> mp;
        mp['R'] = {0, 1};
        mp['L'] = {0, -1};
        mp['U'] = {-1, 0};
        mp['D'] = {1, 0};
        vector<int> ans;
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            int ind = i, count = 0;
            int curX = startPos[0], curY = startPos[1];
            while (ind < sz) {
                int newX = curX + mp[s[ind]].first;
                int newY = curY + mp[s[ind]].second;
                if (newX < 0 || newX >= n || newY < 0 || newY >= n)
                    break;
                curX = newX;
                curY = newY;
                ind++;
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};