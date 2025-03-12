class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int left = 0, right = arr[n - 1], bestValue = 0, minDiff = INT_MAX;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Calculate the sum when replacing elements >= mid with mid
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (arr[i] > mid) ? mid : arr[i];
            }
            
            int diff = abs(sum - target);
            
            // Update best value if difference is minimized
            if (diff < minDiff || (diff == minDiff && mid < bestValue)) {
                bestValue = mid;
                minDiff = diff;
            }
            
            if (sum < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return bestValue;
    }
};
