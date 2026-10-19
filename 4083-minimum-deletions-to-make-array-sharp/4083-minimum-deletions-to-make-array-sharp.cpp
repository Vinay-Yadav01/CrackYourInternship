class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        int ind = 0;
        for (int i = 1; i < n; i++)
            if ((nums[i] ^ nums[ind]) == 0)
                cnt++;
            else
                ind = i;

        return cnt;
    }
};