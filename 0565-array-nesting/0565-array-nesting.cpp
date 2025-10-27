class Solution {
    int dfs(int ind, vector<int>& vis, vector<int>& nums){
        if(vis[ind]) return 0;
        vis[ind] = 1;
        return 1 + dfs(nums[ind], vis, nums);
    }
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        int maxDepth = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                maxDepth = max(maxDepth, dfs(i, vis, nums));
            }
        }
        return maxDepth;
    }
};