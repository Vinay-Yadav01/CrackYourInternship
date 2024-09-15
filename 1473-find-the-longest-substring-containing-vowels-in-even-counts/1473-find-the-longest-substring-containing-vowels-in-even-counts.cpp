class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0;
        unordered_map<string, int> mp;
        vector<int> state(5, 0);
        string curr = "00000";
        mp[curr] = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a')
                state[0] = (state[0] + 1) % 2;
            else if (s[i] == 'e')
                state[1] = (state[1] + 1) % 2;
            else if (s[i] == 'i')
                state[2] = (state[2] + 1) % 2;
            else if (s[i] == 'o')
                state[3] = (state[3] + 1) % 2;
            else if (s[i] == 'u')
                state[4] = (state[4] + 1) % 2;
            curr = "";
            for (int j = 0; j < 5; j++) {
                curr += to_string(state[j]);
            }
            if (mp.find(curr) != mp.end()) {
                ans = max(ans, i - mp[curr]);
            }
            else mp[curr] = i;
        }
        return ans;
    }
};