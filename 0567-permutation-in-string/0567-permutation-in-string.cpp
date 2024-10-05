class Solution {
private:
    bool checkEqual(int a[],int b[]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int c1[26]={0};
        for(int i=0;i<s1.size();i++){
            int index = s1[i]-'a';
            c1[index]++;
        }
        int i=0,c2[26]={0};
        int windowSize=s1.length();
        
        while(i<windowSize && i<s2.length()){
            int index = s2[i]-'a';
            c2[index]++;
            i++;         
        }
        if(checkEqual(c1,c2)) return true;
        while(i<s2.length()){
            char newChar = s2[i];
            int index = newChar - 'a';
            c2[index]++;
            char oldChar = s2[i-windowSize];
            index = oldChar-'a';
            c2[index]--;
            i++;
            if(checkEqual(c1,c2)) return true;
        }       
        return false;
    }
};