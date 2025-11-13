class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int prefix = 0, res = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(i==n-1 || s[i+1]=='1'){ //...11000...0010
                    res += prefix;
                }
            }
            else prefix++;
        }
        return res;
    }
};

