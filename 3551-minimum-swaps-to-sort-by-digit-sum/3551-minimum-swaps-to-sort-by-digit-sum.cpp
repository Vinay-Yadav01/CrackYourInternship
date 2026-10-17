class Solution {
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end(), [&](const int a, const int b) {
            int d1 = digitSum(a);
            int d2 = digitSum(b);
            if (d1 == d2)
                return a < b;
            return d1 < d2;
        });

        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++)
            pos[nums[i]] = i;

        int swaps = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (temp[i] != nums[i]) {
                int ind = pos[temp[i]];
                swap(nums[i], nums[ind]);

                pos[nums[i]] = i;
                pos[nums[ind]] = ind;

                swaps++;
            }
        }
        return swaps;
    }
};