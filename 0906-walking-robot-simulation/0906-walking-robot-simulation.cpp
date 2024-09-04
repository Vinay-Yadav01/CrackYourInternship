class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int maxD = 0;
        unordered_set<string> st;
        for (auto obs : obstacles) {
            string temp = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(temp);
        }
        pair<int, int> dir = {0, 1};
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2) {
                dir = {-dir.second, dir.first};
            } else if (commands[i] == -1) {
                dir = {dir.second, -dir.first};
            } else {
                for (int step = 0; step < commands[i]; step++) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    string newCord = to_string(newX) + "_" + to_string(newY);
                    if (st.find(newCord) != st.end())
                        break;
                    x = newX;
                    y = newY;
                }
            }

            maxD = max(maxD, x * x + y * y);
        }
        return maxD;
    }
};