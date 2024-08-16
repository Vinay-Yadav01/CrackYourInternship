class Solution {
private:
    vector<int> prefixMax(vector<int> height, int n) {
        vector<int> ans(n);
        ans[0] = height[0];
        for (int i = 1; i < n; i++) {
            ans[i] = max(height[i], ans[i - 1]);
        }
        return ans;
    }

    vector<int> suffixMax(vector<int> height, int n) {
        vector<int> ans(n);
        ans[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(height[i], ans[i + 1]);
        }
        return ans;
    }

public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> left = prefixMax(height, n);
        vector<int> right = suffixMax(height, n);

        for (int i = 0; i < n; i++) {
            int leftH = left[i];
            int rightH = right[i];
            ans = ans + min(leftH, rightH) - height[i];
        }
        return ans;
    }
};