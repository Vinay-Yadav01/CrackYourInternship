class Solution {
    int countOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,
                      int rowOff, int colOff) {
        int n = img1.size();
        int count = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int newX = x + rowOff;
                int newY = y + colOff;
                if (newX < 0 || newX >= n || newY < 0 || newY >= n)
                    continue;
                if (img1[x][y] == 1 && img2[newX][newY] == 1)
                    count++;
            }
        }
        return count;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxCount = 0;
        for (int rowOff = -n + 1; rowOff <= n - 1; rowOff++) {
            for (int colOff = -n + 1; colOff <= n - 1; colOff++) {
                int count = countOverlaps(img1, img2, rowOff, colOff);
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};