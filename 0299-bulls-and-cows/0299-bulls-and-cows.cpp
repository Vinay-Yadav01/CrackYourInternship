class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> num(10, 0);
        int n = secret.size();
        for (int i = 0; i < n; i++) {
            num[secret[i] - '0']++;
        }
        int bulls = 0, cows = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                num[secret[i] - '0']--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i] && num[guess[i] - '0'] > 0) {
                cows++;
                num[guess[i] - '0']--;
            }
        }
        string ans = to_string(bulls);
        ans.push_back('A');
        ans += to_string(cows);
        ans.push_back('B');
        return ans;
    }
};