class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        for(int num: nums){
            freq[num]++;
        }
        vector<int> ans(2);
        for(int i = 1; i<freq.size();i++){
            if(freq[i] == 2) ans[0] = i;
            if(freq[i] == 0) ans[1] = i;
        }
        return ans;
    }
};