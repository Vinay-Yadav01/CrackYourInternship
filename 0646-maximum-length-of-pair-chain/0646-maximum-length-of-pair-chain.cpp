class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // sort by end time
        });

        int count = 0, end = INT_MIN;
        for (auto& pair : pairs) {
            if (pair[0] > end) {
                count++;
                end = pair[1];
            }
            cout<<pair[0]<<" "<<pair[1]<<endl;
        }
        return count;
    }
};
