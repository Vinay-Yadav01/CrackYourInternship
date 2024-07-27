class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size=nums.size();
        vector<int> visited(size,0);
        for(int i=0;i<size;i++){
            visited[nums[i]]++;
        }
        for(int i=0;i<size;i++){
            if(visited[i]>=2) return i;
        }
        return 0;
    }
};