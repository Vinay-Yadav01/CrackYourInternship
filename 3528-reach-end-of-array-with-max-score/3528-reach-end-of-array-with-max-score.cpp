class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, 0); // DP array to store maximum scores
        stack<int> st; // Monotonic stack to keep track of indices

        // Traverse the array from right to left
        for (int ind = n - 2; ind >= 0; ind--) {
            while (!st.empty() && nums[st.top()] <= nums[ind]) {
                st.pop(); // Pop smaller or equal elements
            }
            if (!st.empty()) {
                // Calculate the score using the nearest larger element to the right
                dp[ind] = 1LL*nums[ind] * (st.top() - ind) + dp[st.top()];
            } else {
                // If no larger element exists, use default score
                dp[ind] = 1LL*nums[ind] * (n - ind - 1);
            }
            st.push(ind); // Push current index to the stack
        }

        // Return the maximum score starting from index 0
        return dp[0];
    }
};
