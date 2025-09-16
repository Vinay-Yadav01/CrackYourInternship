class Solution {
    int gcd(int num1, int num2) {
        if (num2 == 0)
            return num1;
        return gcd(num2, num1 % num2);
    }
    int lcm(int num1, int num2) { return ((long long)num1 * num2) / gcd(num1, num2); }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (!st.empty() && gcd(num, st.top()) > 1) {
                num = lcm(num, st.top());
                st.pop();
            }
            st.push(num);
        }
        vector<int> ans(st.size());
        int ind = st.size() - 1;
        while (!st.empty()) {
            ans[ind] = st.top();
            st.pop();
            ind--;
        }
        return ans;
    }
};