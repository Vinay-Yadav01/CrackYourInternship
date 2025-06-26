class SummaryRanges {
    set<int> st;

public:
    SummaryRanges() {}

    void addNum(int value) { st.insert(value); }

    vector<vector<int>> getIntervals() {
        vector<int> nums(st.begin(), st.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            while (i < n - 1 && nums[i] + 1 == nums[i + 1])
                i++;
            ans.push_back({start, nums[i]});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */