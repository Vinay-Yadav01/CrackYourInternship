class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        int aliceCnt = 0, bobCnt = 0;
        vector<string> res;
        for (int i = 0; i < n; i++) {
            bool aliceReq = rain[i] & (i < n - 1 ? rain[i + 1] : 0);
            bool bobReq = rain[i];
            if (!aliceReq && !bobReq)
                res.push_back("None");
            else if (!aliceReq) {
                bobCnt++;
                res.push_back("Bob");
            } else if (!bobReq) {
                aliceCnt++;
                res.push_back("Alice");
            } else {
                if (aliceCnt <= bobCnt) {
                    aliceCnt++;
                    res.push_back("Alice");
                } else if (aliceCnt > bobCnt) {
                    bobCnt++;
                    res.push_back("Bob");
                }
            }
        }
        return res;
    }
};