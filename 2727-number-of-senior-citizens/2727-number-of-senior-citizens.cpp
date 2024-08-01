class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto i: details){
            int age = stoi(i.substr(11, 2));
            if(age>60) ans++;
        }
        return ans;
    }
};