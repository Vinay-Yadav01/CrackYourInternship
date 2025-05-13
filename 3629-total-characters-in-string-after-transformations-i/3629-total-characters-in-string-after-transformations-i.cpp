class Solution {
public:
    const int MOD=1e9+7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long>curr(26,0);
        vector<long long>next(26,0);

        for(auto it:s){
            curr[it-'a']++;
            next[it-'a']++;
        }

        while(t--){
            for(int i=0;i<26;i++){
                if(i==25&&curr[i]>0){
                    next[0]+=curr[i]%MOD;
                    next[1]+=curr[i]%MOD;
                    next[i]-=curr[i]%MOD;
                    curr[i]=0;

                }
                else if(i<25){
                    next[i+1]+=curr[i]%MOD;
                    next[i]-=curr[i]%MOD;
                    curr[i]=0;
                }
            }

            curr=next;
        }

        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+next[i])%MOD;
        }

        return ans%MOD;
    }
};