class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> arr;  // {value, original index}

        for (int i = 0; i < n; ++i) {
            arr.emplace_back(nums[i], i);
        }

        mergeSort(arr, 0, n - 1, ans);
        return ans;
    }

    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& ans) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ans);
        mergeSort(arr, mid + 1, right, ans);

        vector<pair<int, int>> temp;
        int i = left, j = mid + 1;
        int rightCounter = 0;

        while (i <= mid && j <= right) {
            if (arr[i].first <= arr[j].first) {
                ans[arr[i].second] += rightCounter;
                temp.push_back(arr[i++]);
            } else {
                rightCounter++;
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) {
            ans[arr[i].second] += rightCounter;
            temp.push_back(arr[i++]);
        }

        while (j <= right) {
            temp.push_back(arr[j++]);
        }

        for (int k = left; k <= right; ++k) {
            arr[k] = temp[k - left];
        }
    }
};
