class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for (auto num : nums) {
            pq.push(num);
        }
        while (k--) {
            int maxi = pq.top();
            ans += maxi;
            pq.pop();
            pq.push(ceil(1.0*maxi / 3));
        }
        return ans;
    }
};