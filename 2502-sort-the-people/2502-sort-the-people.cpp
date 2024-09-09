class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int, string>> temp;
        int n = names.size();
        for (int i = 0; i < n; i++) {
            temp.push_back({heights[i], names[i]});
        }
        sort(temp.rbegin(), temp.rend());
        for (auto it : temp) {
            cout<<it.first<<" "<<it.second<<endl;
            ans.push_back(it.second);
        }
        return ans;
    }
};