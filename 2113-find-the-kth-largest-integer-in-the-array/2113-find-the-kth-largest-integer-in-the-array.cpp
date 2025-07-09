struct comp {
    bool operator()(const string& a, const string& b) const {
        if (a.size() == b.size())
            return a > b;
        return a.size() > b.size();
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comp> pq;
        for (auto& it : nums) {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
