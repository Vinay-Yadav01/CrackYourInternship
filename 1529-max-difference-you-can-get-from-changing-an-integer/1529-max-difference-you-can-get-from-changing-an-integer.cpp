class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int maxVal = num;
        int minVal = num;
        for (char a = '0'; a <= '9'; ++a) {
            for (char b = '0'; b <= '9'; ++b) {
                string temp = s;
                for (char& c : temp) {
                    if (c == a)
                        c = b;
                }
                if (temp[0] == '0')
                    continue;
                int val = stoi(temp);
                maxVal = max(maxVal, val);
                minVal = min(minVal, val);
            }
        }

        return maxVal - minVal;
    }
};
