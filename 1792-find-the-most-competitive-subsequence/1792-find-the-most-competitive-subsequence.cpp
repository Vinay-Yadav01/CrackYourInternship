class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        int n = nums.size();
        int toRemove = n - k; 
        for (int d : nums) {
            while (!stack.empty() && stack.back() > d && toRemove > 0) {
                stack.pop_back();
                toRemove--;
            }
            stack.push_back(d);
        }

        stack.resize(k);
        return stack;
    }
};