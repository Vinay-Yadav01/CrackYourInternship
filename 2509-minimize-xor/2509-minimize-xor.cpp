class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = 0;
        int setBits2 = 0;
        int temp = num2;
        int temp2 = num1;
        while (temp || temp2) {
            setBits += temp & 1;
            setBits2 += temp2 & 1;
            temp >>= 1;
            temp2 >>= 1;
        }
        cout << setBits << " " << setBits << endl;
        cout << num1 << " " << num2;
        if (setBits == setBits2)
            return num1;
        int ans = 0;
        for (int i = 31; i >= 0 && setBits; i--) {
            int bit = (1 << i);
            if (num1 & bit) {
                ans ^= (1 << i);
                setBits--;
            }
        }
        int i = 0;
        while (setBits && i < 31) {
            int bit = (1 << i);
            if ((num1 & bit) == 0) {
                ans ^= (1 << i);
                setBits--;
            }
            i++;
        }
        return ans;
    }
};
