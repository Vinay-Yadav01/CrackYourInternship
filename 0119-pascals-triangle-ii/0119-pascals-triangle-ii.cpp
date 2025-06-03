class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        long long prevAns = 1;
        for (int col = 1; col <= rowIndex; col++) {
            prevAns *= (rowIndex - col + 1);
            prevAns /= (col);
            ans.push_back(prevAns);
        }
        return ans;
    }
};