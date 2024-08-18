class Solution {
private:
    bool isValid(string s, int k){
        int zeroCount=0, oneCount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') zeroCount++;
            else oneCount++;
        }
        return (zeroCount<=k || oneCount<=k); 
    }
public:
    int countKConstraintSubstrings(string s, int k) {
        int count=0;
        int n = s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string temp  = s.substr(i,j-i+1);
                if(isValid(temp,k)) count++;
            }
        }
        return count;
    }
};