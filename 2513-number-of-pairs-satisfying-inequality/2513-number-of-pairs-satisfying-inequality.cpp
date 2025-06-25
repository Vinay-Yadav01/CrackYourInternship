class Solution {
public:
    long long mergeSort(vector<int>& arr, int left, int right, int diff) {
        if (left >= right) return 0;

        int mid = (left + right) / 2;
        long long count = mergeSort(arr, left, mid, diff) + mergeSort(arr, mid + 1, right, diff);

        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && arr[i] > arr[j] + diff) j++;
            count += (right - j + 1);
        }

        // merge the two sorted halves
        vector<int> temp(right - left + 1);
        int i = left, k = 0;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];
        for (int t = 0; t < temp.size(); t++) arr[left + t] = temp[t];

        return count;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> diffArray(n);
        for (int i = 0; i < n; i++) {
            diffArray[i] = nums1[i] - nums2[i];
        }
        return mergeSort(diffArray, 0, n - 1, diff);
    }
};
