class Solution {
private:
    // Helper function to check if the subarray is sorted in consecutive ascending order
    bool isSort(vector<int>& nums, int s, int e) {
        while (s < e) {
            if (nums[s] + 1 != nums[s + 1])  // Check if consecutive elements are in ascending order
                return false;
            s++;
        }
        return true;
    }

public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;  // Deque to store indices of potential maximums in the current window

        // First window processing
        for (int i = 0; i < k; i++) {
            // Remove elements from the deque that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);  // Add the current element index
        }

        // Check if the first window is sorted
        if (isSort(nums, 0, k - 1))  // Correct the range to be from 0 to k-1
            ans.push_back(nums[dq.front()]);  // Get the maximum element from the deque
        else
            ans.push_back(-1);

        // Process the rest of the windows
        for (int i = k; i < nums.size(); i++) {
            // Remove elements out of the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);  // Add the current element index

            // Check if the current window is sorted
            if (isSort(nums, i - k + 1, i))  // Correct the range for the new window
                ans.push_back(nums[dq.front()]);  // Get the maximum element from the deque
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
