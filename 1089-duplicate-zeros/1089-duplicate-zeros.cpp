class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        for (int a : arr) {
            if (a != 0)
                res.push_back(a);
            else {
                res.push_back(a);
                if (res.size() < n)
                    res.push_back(a);
            }

            if (res.size() == n)
                break;
        }
        arr = res;
    }
};