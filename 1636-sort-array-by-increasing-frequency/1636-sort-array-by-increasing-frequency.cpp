class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (int num : nums)
            ump[num]++;

        map<int, vector<int>> mp;
        for (auto& [num, cnt] : ump)
            mp[cnt].push_back(num);

        vector<int> res;
        for (auto& [freq, arr] : mp) {
            sort(arr.begin(), arr.end());
            for (int i = arr.size() - 1; i >= 0; i--) {
                int f = freq;
                while (f > 0) {
                    res.push_back(arr[i]);
                    f--;
                }
            }
        }
        return res;
    }
};