class NumArray {
    vector<int> arr;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr = vector<int>(n, 0);
        arr[0] = nums[0];
        for (int i = 1; i < n; i++) {
            arr[i] = nums[i] + arr[i - 1];
        }
    }

    int sumRange(int left, int right) {
        int sum = arr[right];
        if (left > 0)
            sum -= arr[left - 1];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */