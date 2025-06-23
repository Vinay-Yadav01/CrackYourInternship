class Solution {
    bool isPalindrome(int no){
        string s = to_string(no);
        int left=0,right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    bool isprime(int n) {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0)
                return false;
        return true;
    }

public:
    int primePalindrome(int n) {
        int no = n==1?2:n;
        while(1){
            if((no>1e3 and no<1e4) or
               (no>1e5 and no<1e6) or
               (no>1e7 and no<1e8)){
                no = pow(10,ceil(log10(no)));;
                continue;
               }
            if(isprime(no) and isPalindrome(no))
                return no;
            no++;
        }
        return -1;
    }
};
