class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> countDevices;
        int n = bank.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                char ch = bank[i][j];
                if (ch == '1')
                    count++;
            }
            if (count > 0)
                countDevices.push_back(count);
        }
        int laserCount = 0;
        for (int i = 1; i < countDevices.size(); i++) {
            laserCount += (countDevices[i - 1] * countDevices[i]);
        }
        return laserCount;
    }
};