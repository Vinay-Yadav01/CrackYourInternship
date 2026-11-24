class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, int b) {
        return (a / gcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            int gcdVal = 0;
            long long lcmVal = 1;
            long long prod = 1; 
            
            for (int j = i; j < n; ++j) {
                gcdVal = gcd(gcdVal, nums[j]);
                lcmVal = lcm(lcmVal, nums[j]);

                // Break if LCM exceeds a reasonable limit
                if (lcmVal > 1e9)
                    break;

                // Simulate product using modulo to avoid overflow
                prod = (prod * nums[j]);
                if (prod > 1e9)
                    break;

                // Validate the condition
                if (prod == lcmVal * gcdVal) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }
};
