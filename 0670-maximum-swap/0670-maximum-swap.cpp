class Solution {
public:
    int maximumSwap(int num) {
        if (num <= 10)
            return num;
        string temp = to_string(num);
        int n = temp.size();
        vector<int> maxIndex(n, 0);
        int maxValueIndex = n - 1;
        maxIndex[n - 1] = maxValueIndex;
        for (int i = n - 2; i >= 0; i--) {
            if (temp[i] > temp[maxValueIndex]) {
                maxValueIndex = i;
            }
            maxIndex[i] = maxValueIndex;
        }
        for (int i = 0; i < n; i++) {
            if (maxIndex[i] != i && temp[i] != temp[maxIndex[i]]) {
                swap(temp[i], temp[maxIndex[i]]);
                break;
            }
        }
        return stoi(temp);
    }
};