class Solution {
    bool isPossible(vector<int>& nums, int k, int n) {
        int lastMax = -1;
        for (int i = 0; i < n; i += k) {
            int drops = 0;
            int currentMin = nums[i], currentMax = nums[i];

            for (int j = i; j < i + k; j++) {
                if (nums[j] > nums[i + (j - i + 1) % k])
                    drops++;

                if (nums[j] < currentMin)
                    currentMin = nums[j];
                if (nums[j] > currentMax)
                    currentMax = nums[j];
            }

            if (drops > 1)
                return false;

            if (currentMin < lastMax)
                return false;

            lastMax = currentMax;
        }
        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (isPossible(nums, i, n))
                    total += i;
                if (i * i != n) {
                    if (isPossible(nums, n / i, n))
                        total += (n / i);
                }
            }
        }
        return total;
    }
};
