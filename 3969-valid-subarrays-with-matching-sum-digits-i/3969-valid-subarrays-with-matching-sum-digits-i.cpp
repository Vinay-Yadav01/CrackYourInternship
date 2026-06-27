class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum % 10 == x) {
                    long long temp = sum;
                    while (temp >= 10)
                        temp /= 10;

                    if (temp == x) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};