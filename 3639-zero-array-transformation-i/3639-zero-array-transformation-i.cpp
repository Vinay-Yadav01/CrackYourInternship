class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            }
        }
        if (zeroCount == n)
            return true;
        vector<int> diff(n+1,0);
        int sum=0;
        int pos=0;
        for(int i=0;i<n;++i){
            while(sum + diff[i] < nums[i]){
                if(pos==queries.size())//All Queries done?
                    return false;
                
                int start = queries[pos][0];
                int end = queries[pos][1];
                pos++;
                
                if(end < i) continue; //Skip past update

                //Range update in O(1)
                diff[max(start,i)]++;
                diff[end+1]--;
            }
            sum += diff[i];
        }
        return true;
    }
};