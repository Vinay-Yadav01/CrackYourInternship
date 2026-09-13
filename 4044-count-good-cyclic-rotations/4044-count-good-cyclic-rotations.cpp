class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        long long total = 0, first = 0;
        
        for (int i = 0; i < n; i++) {
            total += nums[i];
            if (i < half)
                first += nums[i];
        }
        
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            if (first > total - first) 
                res++;
            first -= nums[i];
            first += nums[(i + half) % n];
        }
        
        return res;
    }
};