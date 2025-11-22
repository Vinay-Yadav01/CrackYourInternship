class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int num : nums)
            sum += num;
        int ans = 0;
        if (sum == goal)
            return ans;
        sum = abs(sum - goal);
        ans += sum / limit;
        ans += (sum % limit != 0 ? 1: 0);
        return ans;
    }
};