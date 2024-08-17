class Solution {
private:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int n = arr.size();
        int sum = 0;
        int mod = 1000000007;
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            sum = (sum + (right * left * 1LL * arr[i]) % mod) % mod;
        }
        return sum;
    }
};