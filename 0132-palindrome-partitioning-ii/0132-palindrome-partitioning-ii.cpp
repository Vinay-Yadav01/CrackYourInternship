class Solution {
    bool isPalindrome(int i, int j, string& s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int solve(int i, string &s, vector<int> &dp){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCost = INT_MAX;
        for(int j=i;j<s.size();j++){
            if(isPalindrome(i,j,s)){
                minCost = min(minCost, 1+solve(j+1,s,dp));
            }
        }
        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp)-1; 
    }
};