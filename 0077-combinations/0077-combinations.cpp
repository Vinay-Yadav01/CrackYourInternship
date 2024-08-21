class Solution {
private:
    void solve(int n,int ind, int k,vector<int> &temp, vector<vector<int>>& ans){
        if(temp.size()>=k){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<=n;i++){
            temp.push_back(i);
            solve(n, i+1,k,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n,1,k, temp, ans);
        return ans;
    }
};