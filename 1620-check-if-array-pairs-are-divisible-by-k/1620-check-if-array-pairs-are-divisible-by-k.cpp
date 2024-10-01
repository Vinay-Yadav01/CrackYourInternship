class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k,0);
        for(auto num: arr){
            int rem = (num%k+k)%k;
            count[rem]++;
        }
        if(count[0]%2!=0) return false;
        for(int i=1;i<=k/2;i++){
            if(count[i]!=count[k-i]) return false;
        }
        return true;
    }
};