class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < m || j < n) {
            int n1 = INT_MAX, n2 = INT_MAX;
            if (i < m) {
                n1 = nums1[i];
            }
            if (j < n) {
                n2 = nums2[j];
            }
            if (n1 < n2) {
                ans.push_back(n1);
                 i++;
            } else {
                ans.push_back(n2);
                j++;
            }
        }
        nums1 = ans;
    }
};