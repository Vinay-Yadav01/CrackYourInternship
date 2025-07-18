class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int real_n = n / 3;
        
        // Step 1: prefix[i] = sum of n largest numbers in nums[i to end]
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        vector<long long> prefix(n, 0);
        long long sum = 0;
        
        for (int i = n - 1; i >= real_n; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > real_n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == real_n) {
                prefix[i] = sum;
            }
        }

        // Step 2: Use maxHeap to track smallest n numbers from start to 2n
        priority_queue<long long> maxHeap;
        sum = 0;
        long long minDiff = LLONG_MAX;
        
        for (int i = 0; i < n - real_n; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > real_n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == real_n) {
                minDiff = min(minDiff, sum - prefix[i + 1]);
            }
        }

        return minDiff;
    }
};
