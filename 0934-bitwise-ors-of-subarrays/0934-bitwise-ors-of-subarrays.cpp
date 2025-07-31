class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans, prev;
        for(int x: arr){
            set<int> curr;
            curr.insert(x);
            for(int y: prev){
                curr.insert(y|x);
            }
            ans.insert(curr.begin(), curr.end());
            prev = curr;
        }
        return ans.size();
    }
};