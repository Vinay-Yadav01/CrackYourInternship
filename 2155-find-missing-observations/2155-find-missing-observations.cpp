class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = 0;
        int m = rolls.size();
        for(int i=0;i<m;i++){
            total+=rolls[i];
        }
        int required = mean*(m+n) - total;
        vector<int> ans;
        if(n*6<required || required<n) return ans;
        while(n){
            int dice = min(6, required-n+1);
            required-=dice;
            ans.push_back(dice);
            n--;
        }
        return ans;
    }
};