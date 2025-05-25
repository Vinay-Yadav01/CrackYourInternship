class Solution {
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int ptr1 = low, ptr2 = mid + 1;
        while (ptr1 <= mid && ptr2 <= high) {
            if (nums[ptr1] < nums[ptr2]) {
                temp.push_back(nums[ptr1]);
                ptr1++;
            } else {
                temp.push_back(nums[ptr2]);
                ptr2++;
            }
        }
        while (ptr1 <= mid) {
            temp.push_back(nums[ptr1]);
            ptr1++;
        }
        while (ptr2 <= high) {
            temp.push_back(nums[ptr2]);
            ptr2++;
        }
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};