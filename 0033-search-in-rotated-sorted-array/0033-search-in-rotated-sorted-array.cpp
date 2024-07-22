class Solution {
private:
    int getPivot(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] >= nums[0])
                s = mid + 1;
            else
                e = mid;
        }
        return e;
    }
    int binarySearch(int s, int e, vector<int>& nums, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        int n = nums.size();
        if (target >= nums[0] && target <= nums[pivot-1])
            return binarySearch(0, pivot - 1, nums, target);
        else
            return binarySearch(pivot, n -1, nums, target);
    }
};