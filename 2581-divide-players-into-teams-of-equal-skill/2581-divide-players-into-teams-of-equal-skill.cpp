class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<int> count(1001, 0);
        int sum = 0;
        for (auto n : skill) {
            sum += n;
            count[n]++;
        }
        int n = skill.size();
        int pair = n / 2;
        if (sum % pair != 0)
            return -1;
        int target = (sum) / pair;
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            int remain = target - skill[i];
            if (count[remain] <= 0)
                return -1;
            ans += (skill[i] * remain);
            count[remain]--;
        }
        return ans / 2;
    }
};