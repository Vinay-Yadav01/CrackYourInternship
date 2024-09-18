class Comp {
public:
    bool operator()(int num1, int num2) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        return s1 + s2 > s2 + s1;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Comp());
        if (nums[0] == 0)
            return "0";
        string ans = "";
        for (auto num : nums) {
            ans += to_string(num);
        }
        return ans;
    }
};