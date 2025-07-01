class Solution {
    void solve(string answerKey, int k, char to_replace, int& ans) {
        int left = 0, count = 0, n = answerKey.size();
        for (int right = 0; right < n; right++) {
            if (answerKey[right] == to_replace)
                count++;
            while (count > k && left < right) {
                count -= (answerKey[left] == to_replace) ? 1 : 0;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        solve(answerKey, k, 'F', ans);
        solve(answerKey, k, 'T', ans);
        return ans;
    }
};