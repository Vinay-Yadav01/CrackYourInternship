class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1 = coordinate1[0]-'a';
        c1+= coordinate1[1] - '1';
        int c2 = coordinate2[0]-'a';
        c2+= coordinate2[1] - '1';
        bool check1 = c1%2==0;
        bool check2 = c2%2==0;
        return check1 == check2;
    }
};