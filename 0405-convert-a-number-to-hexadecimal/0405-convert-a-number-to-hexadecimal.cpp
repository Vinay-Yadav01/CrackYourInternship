class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        cout<<num;
        string mp = "0123456789abcdef";
        string ans = "";
        unsigned int n = (unsigned int)(num); 
        while (n > 0) {
            ans = mp[n % 16] + ans;
            n /= 16;
        }
        return ans;
    }
};