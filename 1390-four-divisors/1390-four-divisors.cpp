class Solution {
    int countDivisor(int num) {
        int cnt = 0, sum = 0;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                int j = num / i;
                if (j == i || cnt > 0)
                    return 0;
                sum += i + j;
                cnt++;
            }
        }
        return (cnt == 1 ? 1 + sum + num : 0);
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans += countDivisor(num);
        }
        return ans;
    }
};