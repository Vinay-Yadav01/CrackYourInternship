random_device rd;
mt19937_64 gen(rd());
class Solution {
    vector<int> original;

public:
    Solution(vector<int>& nums) { this->original = nums; }

    vector<int> reset() { return original; }

    vector<int> shuffle() {
        vector<int> ans = original;
        std::shuffle(ans.begin(), ans.end(), gen);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */