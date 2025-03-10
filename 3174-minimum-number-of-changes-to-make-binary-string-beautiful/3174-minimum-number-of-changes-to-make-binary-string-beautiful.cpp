class Solution {
public:
    int minChanges(string s) {
        vector<int> odd;
        int n = s.size();

        int i = 1;
        int start = 0;
        int count = 0;
        while (i < n) {
            while (i < n and s[i] == s[i - 1])
                i++;

            if ((i - start) & 1)
                odd.push_back(count);

            count++;
            start = i;
            i++;
        }
        if ((i - start) & 1)
            odd.push_back(count);

        int minChanges = 0;
        for (int pos = 1; pos < odd.size(); pos += 2)
            minChanges += odd[pos] - odd[pos - 1];

        return minChanges;
    }
};