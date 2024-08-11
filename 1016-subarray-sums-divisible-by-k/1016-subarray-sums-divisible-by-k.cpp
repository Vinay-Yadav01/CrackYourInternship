class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderFreq;
        remainderFreq[0] = 1;  // To handle cases where prefix sum itself is divisible by k
        int sum = 0, ans = 0;
        
        for (int num : nums) {
            sum += num;
            int remainder = sum % k;
            if (remainder < 0) remainder += k;  // Adjust for negative remainders
            
            if (remainderFreq.find(remainder) != remainderFreq.end()) {
                ans += remainderFreq[remainder];
            }
            remainderFreq[remainder]++;
        }
        
        return ans;
    }
};