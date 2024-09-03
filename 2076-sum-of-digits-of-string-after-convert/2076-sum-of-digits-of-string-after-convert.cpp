class Solution {
    int sumInString(string num){
        int ans=0;
        int i=0;
        while(i<num.size()){
            ans+=num[i]-'0';
            i++;
        }
        return ans;
    }
public:
    int getLucky(string s, int k) {
        string sum="";
        for (int i = 0; i < s.size(); i++) {
            sum = sum + to_string(s[i] - 'a' + 1);
        }
        while (k--) {
            sum = to_string(sumInString(sum));
        }
        return stoi(sum);
    }
};