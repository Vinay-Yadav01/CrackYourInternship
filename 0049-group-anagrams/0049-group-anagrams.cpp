class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        map<string, vector<int>> mp;
        for(int i=0;i<temp.size();i++){
            sort(temp[i].begin(),temp[i].end());
            mp[temp[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            vector<string> arr;
            for(auto ind: it.second){
                arr.push_back(strs[ind]);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};