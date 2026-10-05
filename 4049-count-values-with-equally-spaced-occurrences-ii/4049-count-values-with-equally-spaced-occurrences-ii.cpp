class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> ump;
        for (int ind = 0; ind < nums.size(); ind++)
            ump[nums[ind]].push_back(ind);

        int res = 0;
        for (auto& [num, arr] : ump) {
            if (arr.size() < 3)
                continue;

            bool flag = true;
            int diff = arr[1] - arr[0];
            for (int ind = 2; ind < arr.size(); ind++) {
                if (diff != arr[ind] - arr[ind - 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res++;
        }
        return res;
    }
};