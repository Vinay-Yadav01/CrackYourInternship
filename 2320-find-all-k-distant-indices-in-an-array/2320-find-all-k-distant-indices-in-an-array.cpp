class Solution {
    bool isExist(int ind, vector<int>& index, int k) {
        for (int i : index) {
            if (abs(ind - i) <= k)
                return true;
        }
        return false;
    }

public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans, index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key)
                index.push_back(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isExist(i, index, k))
                ans.push_back(i);
        }
        return ans;
    }
};