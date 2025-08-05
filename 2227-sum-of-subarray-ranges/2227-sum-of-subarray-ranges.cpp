class Solution {
public:
    vector<int> NSE(vector<int>& arr, int n) {
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> PSEE(vector<int>& arr, int n) {
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    vector<int> NGE(vector<int>& arr, int n) {
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> PGEE(vector<int>& arr, int n) {
        vector<int> pgee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long res = 0;

        vector<int> nse = NSE(arr, n);
        vector<int> psee = PSEE(arr, n);

        for (int i = 0; i < n; i++) {
            long long r = nse[i] - i;
            long long l = i - psee[i];
            res = (res + (l * r * arr[i]));
        }
        return res;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long res2 = 0;

        vector<int> nge = NGE(arr, n);
        vector<int> pgee = PGEE(arr, n);

        for (int i = 0; i < n; i++) {
            long long r = nge[i] - i;
            long long l = i - pgee[i];
            res2 = (res2 + (l * r * arr[i]));
        }
        return res2;
    }

    long long subArrayRanges(vector<int>& nums) {
        return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
    }
};