class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // Initialize the answer array with 0s
        stack<int> st; // This will store the indices of the temperatures array
        
        for (int i = n - 1; i >= 0; --i) {
            // Maintain the stack such that the temperatures are in descending order
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            // If the stack is not empty, the top of the stack is the index of the next warmer day
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            // Push the current day's index onto the stack
            st.push(i);
        }
        
        return ans;
    }
};
