class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int count = 0, prevCount = 0, laserCount = 0;
        for (int i = 0; i < n; i++) {
            count = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                char ch = bank[i][j];
                if (ch == '1')
                    count++;
            }
            if (count == 0)
                continue;
            laserCount += (count * prevCount);
            prevCount = count;
        }
        return laserCount;
    }
};