#include<algorithm>
class Solution {
private:
    int common(string str1,string str2){
        int ans=0, i=0,j=0;
        while(i<str1.size() && j<str2.size() && str1[i++]==str2[j++]) ans++;
        return ans;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str=strs[0];
        int ans=str.size();
        for(int i=1;i<strs.size();i++){
            ans = min(ans,common(str,strs[i]));
        }
        return str.substr(0,ans);
    }
};