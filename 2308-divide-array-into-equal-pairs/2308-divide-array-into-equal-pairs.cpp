class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> numCount(501);
        for (int num : nums) {
            numCount[num]++;
        }
        for (int count : numCount) {
            if (count & 1)
                return false;
        }
        return true;
    }
};