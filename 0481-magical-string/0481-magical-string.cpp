class Solution {
public:
    int magicalString(int n) {
        if (n <= 3)
            return 1;
        vector<int> arr(n + 1);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 2;
        int readPointer = 2, writePointer = 3, count = 1;
        while (writePointer < n) {
            int nextGroupSize = arr[readPointer];
            int nextChar = arr[writePointer - 1] == 1 ? 2 : 1;
            for (int i = 0; i < nextGroupSize; i++) {
                if (writePointer < n) {
                    arr[writePointer] = nextChar;
                    if (nextChar == 1)
                        count++;
                    writePointer++;
                }
            }
            readPointer++;
        }
        return count;
    }
};
